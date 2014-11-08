#ifndef GL_BOUNDBUFFEROBJECT_H__
#define GL_BOUNDBUFFEROBJECT_H__

#include <vector>
#include <array>
#include <cstdint>

#include "Flags.h"

#include "TargetLock.h"
#include "BufferObject.h"
#include "MappedBufferObject.h"
#include "Enums.h"

namespace gl
{
class GlContext;

class BoundBufferObject
{
public:
    BoundBufferObject(BufferObject* buffer, GlContext* context, 
            TargetLock lock);
    virtual ~BoundBufferObject() = default;

    BoundBufferObject(const BoundBufferObject& other) = delete;
    BoundBufferObject(BoundBufferObject&& other) noexcept;
    BoundBufferObject& operator =(const BoundBufferObject& other) = delete;
    BoundBufferObject& operator =(BoundBufferObject&& other) noexcept;
    
    void set_data(const void* data);
    template<typename T>
    void set_data(const std::vector<T>& data)
        {set_data(data.data());}

    void set_data(const void* data, intptr_t offset, size_t length);
    template<typename T>
    void set_data(const std::vector<T>& data, intptr_t offset)
        {set_data(data.data(), offset, data.size() * sizeof(T));} 
    template<typename T, size_t N>
    void set_data(const std::array<T, N>& data, intptr_t offset)
        {set_data(data.data(), offset, N * sizeof(T));} 

    void get_data(intptr_t offset, size_t size, char* out) const;
    template<typename T>
    std::vector<T> get_data(intptr_t offset, size_t count) const;
    template<typename T, size_t N>
    std::array<T, N> get_data(intptr_t offset);

    template<typename T>
    MappedBufferObject<T> map(bool can_read)
        {return map<T>(0, m_buffer->size() / sizeof(T), Flags<BufferObject::MappingOptions>(), can_read);}

    template<typename T>
    MappedBufferObject<T> map(const Flags<BufferObject::MappingOptions>& options,
        bool can_read)
        {return map<T>(0, m_buffer->size() / sizeof(T), options, can_read);}

    template<typename T>
    MappedBufferObject<T> map(intptr_t offset, size_t count, 
        const Flags<BufferObject::MappingOptions>& options,
        bool can_read);

    template<typename T>
    MappedBufferObject<const T> map_const(intptr_t offset, size_t count, 
        const Flags<BufferObject::MappingOptions>& options);

    void* map_raw(intptr_t offset, size_t size, 
            const Flags<BufferObject::MappingOptions>& options,
            const Flags<BufferObject::MappingAccess>& access);

    void flush_mapped_buffer_range(intptr_t offset, size_t length);

    void invalidate();

    void release();

protected:
    GLenum raw_target() const {return GL_COPY_WRITE_BUFFER;}

    BufferObject* m_buffer;
    GlContext* m_context;
    TargetLock m_lock;
private:
};

template<typename T>
std::vector<T> BoundBufferObject::get_data(intptr_t offset, size_t count) const
{
    auto data = std::vector<T>(count); 
    get_data(offset, count * sizeof(T), data.data());
    return data;
}

template<typename T, size_t N>
std::array<T, N> BoundBufferObject::get_data(intptr_t offset)
{
    auto data = std::array<T, N>();
    get_data(offset, N * sizeof(T), data.data()); 
    return data;
}

template<typename T>
MappedBufferObject<T> BoundBufferObject::map(intptr_t offset, size_t count, 
    const Flags<BufferObject::MappingOptions>& options, bool can_read)
{
    auto access = Flags<BufferObject::MappingAccess>(BufferObject::MappingAccess::Write);
    auto size = count * sizeof(T);
    if(can_read)
    {
        access |= BufferObject::MappingAccess::Read;
    }
    void* buffer = map_raw(offset, size, options, access);
    auto ret = MappedBufferObject<T>(m_context, m_buffer, reinterpret_cast<T*>(buffer), size);
    return ret;
}
 
template<typename T>
MappedBufferObject<const T> BoundBufferObject::map_const(intptr_t offset, size_t count, 
    const Flags<BufferObject::MappingOptions>& options)
{
    auto size = count * sizeof(T);
    void* buffer = map_raw(offset, size, options, BufferObject::MappingAccess::Read);
    auto ret = MappedBufferObject<const T>(m_context, m_buffer, buffer, size);
    return ret;
}

}

#endif
    
