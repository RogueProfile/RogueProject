#ifndef GLMACROS_H__
#define GLMACROS_H__

#define GL_DEBUG

#ifdef GL_DEBUG
#define CHECK_GL_ERROR(fn) {GLenum err = glGetError(); \
        if(err != GL_NO_ERROR) \
        {\
            throw GlException(#fn, err); \
        }}
#else
#define CHECK_GL_ERROR(fn)
#endif

#endif
