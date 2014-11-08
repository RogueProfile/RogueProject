#ifndef GL_MAPPEDBUFFEROBJECT_H__
#define GL_MAPPEDBUFFEROBJECT_H__

#include <cassert>

#include "GlContext.h"
#include "Enums.h"

namespace gl
{

template<typename T>
class MappedBufferObjectIterator: public std::iterator<
                                  std::random_access_iterator_tag,
                                  T>
{
public:
    MappedBufferObjectIterator(T* data = nullptr);
    ~MappedBufferObjectIterator() = default;

    MappedBufferObjectIterator(const MappedBufferObjectIterator& other) = default;
    MappedBufferObjectIterator(MappedBufferObjectIterator&& other) = default;
    MappedBufferObjectIterator& operator =(const MappedBufferObjectIterator& other) = default;
    MappedBufferObjectIterator& operator =(MappedBufferObjectIterator&& other) = default;

    bool operator ==(const MappedBufferObjectIterator<T>& rhs) const;
    bool operator !=(const MappedBufferObjectIterator<T>& rhs) const;
    bool operator <(const MappedBufferObjectIterator<T>& rhs) const;
    bool operator >(const MappedBufferObjectIterator<T>& rhs) const;
    bool operator <=(const MappedBufferObjectIterator<T>& rhs) const;
    bool operator >=(const MappedBufferObjectIterator<T>& rhs) const;

    MappedBufferObjectIterator& operator +=(ptrdiff_t distance);
    MappedBufferObjectIterator& operator -=(ptrdiff_t distance);

    MappedBufferObjectIterator operator ++() {++m_data; return *this;}
    MappedBufferObjectIterator operator --() {--m_data; return *this;}
    MappedBufferObjectIterator operator ++(int);
    MappedBufferObjectIterator operator --(int);

    operator MappedBufferObjectIterator<const T>() const 
        {return MappedBufferObjectIterator<const T>(m_data);}

    T& operator*() {return *m_data;}
    const T& operator*() const {return *m_data;}
    T* operator->() {return m_data;} 

    friend MappedBufferObjectIterator<T> operator +(const MappedBufferObjectIterator<T>& lhs, 
            ptrdiff_t distance);
    friend MappedBufferObjectIterator<T> operator -(const MappedBufferObjectIterator<T>& lhs,
            ptrdiff_t distance);

    friend ptrdiff_t operator -(const MappedBufferObjectIterator<T>& lhs,
            const MappedBufferObjectIterator<T>& rhs);

    friend void swap(MappedBufferObjectIterator<T>& lhs, MappedBufferObjectIterator<T>& rhs);

private:
    T* m_data;
};

template<typename T>
class MappedBufferObject
{
    friend class gl::BoundBufferObject;
public:
    using iterator = MappedBufferObjectIterator<T>;
    using const_iterator = MappedBufferObjectIterator<const T>;

    MappedBufferObject() {}
    ~MappedBufferObject();

    MappedBufferObject(const MappedBufferObject& other) = delete;
    MappedBufferObject(MappedBufferObject&& other) noexcept;
    MappedBufferObject& operator =(const MappedBufferObject& other) = delete;
    MappedBufferObject& operator =(MappedBufferObject&& other) noexcept;

    T& operator [](size_t index);

    operator MappedBufferObject<const T>() const
    {
        auto ret = MappedBufferObject<const T>(m_context, m_data, m_size);
        m_data = nullptr;
        return ret;
    }

    T* data() {return m_data;}

    bool is_valid() const {return m_data == nullptr;}
    size_t size() const {return m_size;}

    void release();

    friend iterator begin(const MappedBufferObject<T>& obj) {return iterator(obj.m_data);}
    friend iterator end(const MappedBufferObject<T>& obj) {return iterator(obj.m_data+obj.m_size);}
    friend const_iterator cbegin(const MappedBufferObject<T>& obj) {return const_iterator(obj.m_data);}
    friend const_iterator cend(const MappedBufferObject<T>& obj) {return const_iterator(obj.m_data+obj.m_size);}

    iterator begin() {return begin(*this);}
    iterator end() {return end(*this);}
    const_iterator begin() const {return begin(*this);}
    const_iterator end() const {return end(*this);}
    const_iterator cbegin() const {return cbegin(*this);}
    const_iterator cend() const {return cend(*this);}

protected:
    MappedBufferObject(GlContext* context, BufferObject* buffer,
           T* data, size_t size);

    GlContext* m_context = nullptr;
    BufferObject* m_buffer = nullptr;
    T* m_data = nullptr;
    size_t m_size = 0;

private:
};


template<typename T>
inline MappedBufferObject<T>::MappedBufferObject(GlContext* context,
        BufferObject* buffer, T* data, size_t size):
    m_context(context), m_buffer(buffer), m_data(data), m_size(size)
{
}

template<typename T>
MappedBufferObject<T>::~MappedBufferObject()
{
    release();
}
    
template<typename T>
inline MappedBufferObject<T>::MappedBufferObject(MappedBufferObject<T>&& other) noexcept:
    m_context(other.m_context), m_buffer(other.m_buffer), 
    m_data(other.m_data), m_size(other.m_size)
{
    other.m_data = nullptr;
}
 
template<typename T>
inline MappedBufferObject<T>& MappedBufferObject<T>::operator=(MappedBufferObject<T>&& other) noexcept
{
    release();
    m_context = other.m_context;
    m_buffer = other.m_buffer;
    m_data = other.m_data; 
    m_size = other.m_size;
    other.m_data = nullptr;
    return *this;
}

template<typename T>
inline T& MappedBufferObject<T>::operator[](size_t index)
{
    return m_data[index]; 
}

template<typename T>
inline void MappedBufferObject<T>::release()
{
    if(m_data != nullptr)
    {
        glBindBuffer(GL_COPY_WRITE_BUFFER, m_buffer->handle());
        glUnmapBuffer(GL_COPY_WRITE_BUFFER);
        m_context->rebind_buffer_object();
    } 
    m_data = nullptr;
}
    
template<typename T>
void swap(MappedBufferObjectIterator<T>& lhs, MappedBufferObjectIterator<T>& rhs)
{
    using std::swap;
    swap(lhs.m_data, rhs.m_data);
}
 
template<typename T>
inline MappedBufferObjectIterator<T>::MappedBufferObjectIterator(T* data):
    m_data(data)
{ 
}
 
template<typename T>
inline bool MappedBufferObjectIterator<T>::operator==(const MappedBufferObjectIterator<T>& rhs) const
{
    return m_data == rhs.m_data;
}
 
template<typename T>
inline bool MappedBufferObjectIterator<T>::operator!=(const MappedBufferObjectIterator<T>& rhs) const
{
    return !(*this == rhs);
}
 
template<typename T>
inline MappedBufferObjectIterator<T>& MappedBufferObjectIterator<T>::operator+=(ptrdiff_t distance)
{
    m_data += distance;
    return *this; 
}
 
template<typename T>
inline MappedBufferObjectIterator<T>& MappedBufferObjectIterator<T>::operator-=(ptrdiff_t distance)
{
    m_data -= distance;
    return *this; 
}
 
template<typename T>
inline bool MappedBufferObjectIterator<T>::operator<(const MappedBufferObjectIterator<T>& rhs) const
{
    return m_data < rhs.m_data; 
}
 
template<typename T>
inline bool MappedBufferObjectIterator<T>::operator>(const MappedBufferObjectIterator<T>& rhs) const
{
    return rhs < *this; 
}
 
template<typename T>
inline bool MappedBufferObjectIterator<T>::operator<=(const MappedBufferObjectIterator<T>& rhs) const
{
    return !(*this > rhs);
}
 
template<typename T>
inline bool MappedBufferObjectIterator<T>::operator>=(const MappedBufferObjectIterator<T>& rhs) const
{
    return !(*this < rhs);
}
 
template<typename T>
inline MappedBufferObjectIterator<T> MappedBufferObjectIterator<T>::operator++(int)
{
    auto tmp(*this);
    ++m_data;
    return tmp; 
}
 
template<typename T>
inline MappedBufferObjectIterator<T> MappedBufferObjectIterator<T>::operator--(int)
{
    auto tmp(*this);
    --m_data;
    return tmp; 
}

template<typename T>
inline MappedBufferObjectIterator<T> operator +(const MappedBufferObjectIterator<T>& lhs, 
        ptrdiff_t distance)
{
    auto ret(lhs);
    ret += distance;
    return ret;
}

template<typename T>
inline MappedBufferObjectIterator<T> operator -(const MappedBufferObjectIterator<T>& lhs,
        ptrdiff_t distance)
{    
    auto ret(lhs);
    ret -= distance;
    return ret;
}

template<typename T>
inline ptrdiff_t operator -(const MappedBufferObjectIterator<T>& lhs,
      const MappedBufferObjectIterator<T>& rhs)
{
    return std::distance(rhs.m_data, lhs.m_data); 
}

}

#endif
    
