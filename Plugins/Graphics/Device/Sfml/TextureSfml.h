#ifndef __AE_GRAPHICS_DEVICE_TEXTURE_SFML__
#define __AE_GRAPHICS_DEVICE_TEXTURE_SFML__

#include "Anima/Graphics/Device/Texture.h"

#include "SFML/Graphics.hpp"

#include <memory>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class TextureSfml : public AE::Graphics::Device::Texture
			{
			private:
				sf::Texture		mSfmlTexture;

			public:
				TextureSfml(const AE::Math::Vector2 &dimensions, void *data = nullptr, bool hasMipMap = false);
				TextureSfml(const AE::Graphics::Image &image);
				~TextureSfml();

				AE::Math::Vector2 GetDimensions();

				sf::Texture&		GetSfmlTexture() { return mSfmlTexture; }
				const sf::Texture&	GetSfmlTexture() const { return mSfmlTexture; }
				sf::Texture*		GetSfmlTexturePtr() { return &mSfmlTexture; }
			};

			typedef std::unique_ptr<AE::Graphics::Device::TextureSfml> TextureSfmlPtr;
		}
	}
}

#endif