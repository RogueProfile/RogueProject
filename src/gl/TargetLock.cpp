#include "TargetLock.h"

namespace gl
{

TargetLock::TargetLock(GlObject* object, GlObject** target):
    m_lock_target(target), m_object(object)
{
}
 
TargetLock::~TargetLock()
{
    release();
}
 
TargetLock::TargetLock(TargetLock&& other) noexcept:
    m_lock_target(other.m_lock_target), m_object(other.m_object)
{
    other.m_lock_target = nullptr; 
}
 
TargetLock& TargetLock::operator=(TargetLock&& other) noexcept
{
    release();
    m_lock_target = other.m_lock_target;
    other.m_lock_target = nullptr; 
    return *this;
}
 
void TargetLock::release()
{
    if(m_lock_target != nullptr)
    {
        *m_lock_target = nullptr;
        m_lock_target = nullptr;
    } 
}
 
}

