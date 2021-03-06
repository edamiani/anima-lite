#ifndef __ANIMA_GRAPHICS_IMAGE__
#define __ANIMA_GRAPHICS_IMAGE__

#include "Anima/Graphics/ColorBuffer.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Graphics/Image/ImageDesc.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Math/Vector2.h"
#include "Anima/Types.h"

#include <string>

namespace AE
{
	namespace Graphics
	{
		class Image
		{
		protected:
			void						*mData;
			AE::Math::Vector2			mDimensions;
			std::string					mFile;
			AE::Graphics::ImageFormat	mImageFormat;

		public:
			Image(const std::string &filename) :
				mFile(filename) {}

			Image(const AE::Math::Vector2 &dimensions) :
				mDimensions(dimensions) {}

			virtual ~Image() {}

			void* GetData() const { return mData; }
			AE::Math::Vector2 GetDimensions() const { return mDimensions; }
		};
	}
}

#endif