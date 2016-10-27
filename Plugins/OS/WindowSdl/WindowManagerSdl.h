#ifndef __AE_OS_WINDOW_MANAGER_SDL__
#define __AE_OS_WINDOW_MANAGER_SDL__

#include "Anima/OS/WindowManager.h"

#include "Anima/Platform.h"
#include "Anima/Types.h"

#include <list>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class Manager;
		}
	}

	namespace OS
	{
		class WindowManagerSdl : public AE::OS::WindowManager
		{
		public:
			WindowManagerSdl();
			//WindowManagerSdl(AE::Graphics::Device::Manager *deviceManager);
			~WindowManagerSdl();

			bool Install(AE::uint options);
			bool Uninstall();

			AE::OS::Window* createWindow(AE::OS::WindowDesc &windowDesc);
			AE::OS::Window* createWindow(AE::OS::WindowDesc &windowDesc, AE::Graphics::Device::Context *deviceContext);
			void destroyWindow(AE::OS::Window *window);

		private:
			AE::uint8 mCurrentId = 0;
		};
	}
}

#endif