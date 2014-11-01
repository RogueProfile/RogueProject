#ifndef GL_TARGETLOCK_H__
#define GL_TARGETLOCK_H__

namespace gl
{
class GlObject;

class TargetLock
{
public:
    TargetLock(GlObject* object, GlObject** target);
    ~TargetLock();

    TargetLock(const TargetLock& other) = delete;
    TargetLock(TargetLock&& other) noexcept;
    TargetLock& operator =(const TargetLock& other) = delete;
    TargetLock& operator =(TargetLock&& other) noexcept;

    void release();
protected:
    GlObject** m_lock_target = nullptr;
    GlObject* m_object = nullptr; 
private:
};

}

#endif
    
