#ifndef __AE_GRAPHICS_DEVICE_CONTEXT_SDL__
#define __AE_GRAPHICS_DEVICE_CONTEXT_SDL__

#include "Anima/Graphics/Device/Context.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/ContextDesc.h"
#include "Anima/OS/Window.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

#include <vector>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class ContextSdl : public AE::Graphics::Device::Context
			{
			public:
				ContextSdl(AE::Graphics::Device::ContextDesc &contextDesc, AE::Graphics::Device::Driver *deviceDriver);
				virtual ~ContextSdl();

				bool BeginRendering();
				bool BeginRendering(const AE::Graphics::Color &clearColor);
				//AE::uint createDrawingContext(AE::OS::Window *window, AE::Graphics::SurfaceFormat surfaceFormat);
				//AE::Graphics::Surface* createOffscreenSurface(const AE::Math::Point2 &dimensions, AE::Graphics::SurfaceFormat surfaceFormat, bool usesVideoMemory);
				void Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				void Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer, AE::Graphics::Device::IndexBuffer *indexBuffer) {}
				void DrawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color);
				void EndRendering();
				void Render();
				void SetFullScreen(bool isFullScreen);
				void SetParentWindow(AE::OS::Window *parentWindow);

			protected:
				SDL_Renderer *mRenderer;
			};
		}
	}
}

#endif