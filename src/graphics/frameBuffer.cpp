#include "frameBuffer.h"
#include <iostream>


namespace mike { namespace graphics {


FrameBuffer::FrameBuffer(int width, int height)
{
glGenFramebuffers(1, &m_ID);
bind();
m_texture = new Texture(width,height);
glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture->getID(), 0);
glGenRenderbuffers(1, &m_rbo);
glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);
glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
//glBindRenderbuffer(GL_RENDERBUFFER, 0);
glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_rbo);
if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

FrameBuffer::~FrameBuffer()
{
glDeleteFramebuffers(1,&m_ID);
}

void FrameBuffer::bind()
{
glBindFramebuffer(GL_FRAMEBUFFER, m_ID);
}

void FrameBuffer::unbind()
{
glBindFramebuffer(GL_FRAMEBUFFER, 0);
}




}
}
