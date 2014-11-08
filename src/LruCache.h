#ifndef LRUCACHE_H__
#define LRUCACHE_H__

#include <list>
#include <unordered_map>

template<typename Key, typename Type>
class LruCache
{
public:
	LruCache(size_t capacity, std::function<void (const Key&, const Type&)> deletion_callback = nullptr):
		m_capacity(capacity), m_deletion_callback(std::move(deletion_callback))
	{
	}

	~LruCache() = default;

	LruCache(const LruCache&) = delete;
	LruCache& operator =(const LruCache&) = delete;

	LruCache(LruCache&& other) noexcept:
		m_items(std::move(other.m_items)), m_order(std::move(other.m_order)),
		m_capacity(other.m_capacity)
	{

	}

	LruCache& operator =(LruCache&& other) noexcept
	{
		if(&other != this)
		{
			m_items = std::move(other.m_items);
			m_order = std::move(other.m_order);
			m_capacity = other.m_capacity;
		}
		return *this;
	}

	Type* get_item(const Key& key);
	const Type& add_item(const Key& key, Type item);

	void resize(size_t new_size);

	void clear();

	size_t size() const {return m_items.size();}
	bool empty() const {return m_items.empty();}
	size_t capacity() const {return m_capacity;}

	void drop_one();

protected:

	struct CacheItem
	{
		Type value;
		typename std::list<Key>::iterator it;
	};

	std::unordered_map<Key, CacheItem> m_items;
	std::list<Key> m_order;
	std::function<void (const Key&, const Type&)> m_deletion_callback;

	size_t m_capacity;
};

template<typename Key, typename Type>
inline Type* LruCache<Key, Type>::get_item(const Key& key)
{
	auto it = m_items.find(key);
	if(it != m_items.end())
	{
		m_order.splice(m_order.begin(), m_order, it->second.it);
		it->second.it = m_order.begin();
		return &it->second.value;
	}

	return nullptr;
}

template<typename Key, typename Type>
inline const Type& LruCache<Key, Type>::add_item(const Key& key, Type item)
{
	m_order.push_front(key);
	CacheItem cache_item = {std::move(item), m_order.begin()};
	auto it = m_items.emplace(std::make_pair(key, cache_item)).first;

	if(m_items.size() > m_capacity)
	{
		drop_one();
	}
    return it->second.value;
}

template<typename Key, typename Type>
inline void LruCache<Key, Type>::resize(size_t new_size)
{
	while(new_size < m_items.size())
	{
		auto& last_item = m_order.back();
		m_items.erase(last_item);
		m_order.pop_back();
	}
	m_capacity = new_size;
}

template<typename Key, typename Type>
inline void LruCache<Key, Type>::clear()
{
	m_items.clear();
	m_order.clear();
}

template<typename Key, typename Type>
inline void LruCache<Key, Type>::drop_one()
{
	auto& item = m_order.back();
	if(m_deletion_callback)
	{
		m_deletion_callback(item, m_items[item].value);
	}
	m_items.erase(item);
	m_order.pop_back();
}

#endif
