#include "ContextSfml.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/PixelBufferDesc.h"

#include "Plugins/Graphics/Device/Sfml/TextureSfml.h"

#include <cassert>
#include <cstring>
#include <string>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			ContextSfml::ContextSfml(AE::Graphics::Device::ContextDesc &contextDesc, AE::Graphics::Device::Driver *deviceDriver) 
				: Context(deviceDriver)
			{
				AE::OS::Window *window = contextDesc.parentWindow;

				sf::ContextSettings settings;
				settings.majorVersion = 3;
				settings.minorVersion = 1;
				settings.antialiasingLevel = 0;
				settings.depthBits = 24;
				settings.stencilBits = 8;
				settings.attributeFlags |= sf::ContextSettings::Core;

				mSfmlWindow.create(window->GetHandle(), settings);

				contextDesc.parentWindow->AttachDeviceContext(this);
			}

			ContextSfml::~ContextSfml()
			{

			}

			bool ContextSfml::BeginRendering()
			{
				mSfmlWindow.clear();

				return true;
			}

			bool ContextSfml::BeginRendering(const AE::Graphics::Color &clearColor)
			{
				mSfmlWindow.clear(sf::Color(clearColor.R, clearColor.G, clearColor.B, clearColor.A));

				return true;
			}

			void ContextSfml::DrawTexture(AE::Graphics::Device::TexturePtr const &texture, AE::Math::Transform2 &transform)
			{
				sf::Texture *sfmlTexture = reinterpret_cast<AE::Graphics::Device::TextureSfmlPtr &>(const_cast<AE::Graphics::Device::TexturePtr &>(texture))->GetSfmlTexturePtr();

				sf::Vertex quadVertices[4];

				sf::Vector2i dimensions = (sf::Vector2i)sfmlTexture->getSize();

				/*quadVertices[0].position = sf::Vector2f(0, 0);
				quadVertices[0].texCoords = sf::Vector2f(0, 0);
				quadVertices[1].position = sf::Vector2f(0, dimensions.y);
				quadVertices[1].texCoords = sf::Vector2f(0, dimensions.y);
				quadVertices[2].position = sf::Vector2f(dimensions.x, 0);
				quadVertices[2].texCoords = sf::Vector2f(dimensions.x, 0);
				quadVertices[3].position = sf::Vector2f(dimensions.x, dimensions.y);
				quadVertices[3].texCoords = sf::Vector2f(dimensions.x, dimensions.y);*/

				quadVertices[0].position = sf::Vector2f(-dimensions.x / 2.0f, -dimensions.y / 2.0f);
				quadVertices[0].texCoords = sf::Vector2f(0, 0);
				quadVertices[1].position = sf::Vector2f(-dimensions.x / 2.0f, dimensions.y / 2.0f);
				quadVertices[1].texCoords = sf::Vector2f(0, dimensions.y);
				quadVertices[2].position = sf::Vector2f(dimensions.x / 2.0f, -dimensions.y / 2.0f);
				quadVertices[2].texCoords = sf::Vector2f(dimensions.x, 0);
				quadVertices[3].position = sf::Vector2f(dimensions.x / 2.0f, dimensions.y / 2.0f);
				quadVertices[3].texCoords = sf::Vector2f(dimensions.x, dimensions.y);

				sf::RenderStates renderStates;
				renderStates.texture = sfmlTexture;

				AE::Math::Matrix3 m = transform.GetMatrix();
				sf::Transform sfmlTransform(
					m(0, 0), m(1, 0), m(2, 0),
					m(0, 1), m(1, 1), m(2, 1),
					m(0, 2), m(1, 2), m(2, 2)
				);

				renderStates.transform = sfmlTransform;

				mSfmlWindow.draw(quadVertices, 4, sf::TriangleStrip, renderStates);
			}

			void ContextSfml::DrawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color)
			{
				//SDL_SetRenderDrawColor(mRenderer, color.R, color.G, color.B, color.A);
				//SDL_RenderDrawLine(mRenderer, start.x(), start.y(), end.x(), end.y());
			}

			void ContextSfml::DrawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Color &color)
			{
				sf::Vertex quadVertices[4];
				sf::Color sfColor = sf::Color(color.R, color.G, color.B, color.A);

				quadVertices[0].position = sf::Vector2f(topLeft.x(), topLeft.y());
				quadVertices[0].color = sfColor;
				quadVertices[1].position = sf::Vector2f(topLeft.x(), bottomRight.y());
				quadVertices[1].color = sfColor;
				quadVertices[2].position = sf::Vector2f(bottomRight.x(), topLeft.y());
				quadVertices[2].color = sfColor;
				quadVertices[3].position = sf::Vector2f(bottomRight.x(), bottomRight.y());
				quadVertices[3].color = sfColor;

				mSfmlWindow.draw(quadVertices, 4, sf::TriangleStrip);
			}

			void ContextSfml::DrawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Device::Texture &texture)
			{
				sf::Vertex quadVertices[4];

				quadVertices[0].position = sf::Vector2f(topLeft.x(), bottomRight.y());
				quadVertices[0].color = sf::Color(255, 255, 255, 255);
				quadVertices[1].position = sf::Vector2f(bottomRight.x(), bottomRight.y());
				quadVertices[1].color = sf::Color(255, 255, 255, 255);
				quadVertices[2].position = sf::Vector2f(bottomRight.x(), topLeft.y());
				quadVertices[2].color = sf::Color(255, 255, 255, 255);
				quadVertices[3].position = sf::Vector2f(topLeft.x(), topLeft.y());
				quadVertices[3].color = sf::Color(255, 255, 255, 255);

				mSfmlWindow.draw(quadVertices, 4, sf::Quads);
			}

			void ContextSfml::EndRendering()
			{
				mSfmlWindow.display();
			}

			void ContextSfml::Render()
			{
			}

			void ContextSfml::SetFullScreen(bool isFullScreen)
			{
				if(mIsFullScreen)
				{
					/*DEVMODE dm;
					dm.dmSize = sizeof(DEVMODE);
					dm.dmPelsWidth = mParentWindow->getDimensions().x;
					dm.dmPelsHeight = mParentWindow->getDimensions().y;
					dm.dmBitsPerPel = contextDesc.getColorDepth();
					dm.dmDisplayFrequency = 60;
					dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;
					ChangeDisplaySettings(&dm, CDS_FULLSCREEN);*/
				}
			}

			void ContextSfml::SetParentWindow(AE::OS::Window *parentWindow)
			{
				mParentWindow = parentWindow;

				//mDeviceContextHandle = ::GetDC(static_cast<AE::OS::WindowWin *>(mParentWindow)->_getWindowHandle());
			}
		}
	}
}