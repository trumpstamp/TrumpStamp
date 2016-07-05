/*
* Part of the Aeon Framework
* -----------------------------------------------------------------------------
* Aeon Ogre3D Integration Wrapper
*
* File:		OgreSystem.h
  Desc.:	Abstract Ogre System Base class.
* Author:	Felix Bruckner <xography@gatewayheaven.com>
*
* Copyright (c) 2009-2011, gatewayheaven.com. 
*
* Licensed under the Boost Software License.
*
* -----------------------------------------------------------------------------
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (the "Software") to use, reproduce, display, distribute,
* execute, and transmit the Software, and to prepare derivative works of the
* Software, and to permit third-parties to whom the Software is furnished to
* do so, all subject to the following:
* 
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
* -----------------------------------------------------------------------------
*/
#ifndef _AeonOgreSystem_h_
#define _AeonOgreSystem_h_
#include <OgrePrerequisites.h>
#include <OgreWindowEventUtilities.h>
#include <OgreFrameListener.h>

#include <boost/shared_ptr.hpp>

namespace Aeon {

	class AeonOgreSystem: 	public Ogre::FrameListener,
						public Ogre::WindowEventListener {
	public:
		AeonOgreSystem();
		virtual ~AeonOgreSystem(void);

		void initialize( const Ogre::String& pluginConf,
			const Ogre::String& gameConf,
			const Ogre::String& gameLog
			);

	protected:
		Ogre::Root*	root;
		Ogre::RenderWindow*	renderWindow;
		
		Ogre::Log* log;

		// Implement Ogre::FrameListener
		virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
		virtual bool frameStarted(const Ogre::FrameEvent& evt);

		// Implement Ogre::WindowEventListener
		virtual void windowResized(Ogre::RenderWindow* rw);
		virtual void windowClosed(Ogre::RenderWindow* rw);
			
		Ogre::String windowTitle;
		Ogre::String windowHandle;
		bool isDebug;
		bool initialized;

		virtual void loadRendersystems(const Ogre::String& path);
		virtual void loadResources(const Ogre::String &prefix, 
			const Ogre::String &filename);

		virtual Ogre::RenderSystem* selectRenderSystem() = 0;

	private:
		AeonOgreSystem(const AeonOgreSystem& s);
		AeonOgreSystem& operator=(const AeonOgreSystem& s);
	};
}
#endif