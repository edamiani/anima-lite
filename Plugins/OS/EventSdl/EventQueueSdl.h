#ifndef __AE_OS_EVENT_QUEUE_WIN__
#define __AE_OS_EVENT_QUEUE_WIN__

#include "Anima/OS/EventQueue.h"
#include "Anima/Platform.h"

#include <list>

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace OS
	{
		class Window;

		class EventQueueSdl : public AE::OS::EventQueue
		{
		public:
			EventQueueSdl();
			virtual ~EventQueueSdl();

			bool GetNextEvent();
			bool PeekNextEvent();
			bool PollEvents();
			bool WaitNextEvent();

		private:
			bool OnEvent(SDL_Event *event);
		};
	}
}

#endif