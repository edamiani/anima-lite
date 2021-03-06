#include "TestPhysicsBox2D.h"

#include "Plugins/Graphics/Device/Sfml/TextureSfml.h"
#include "Plugins/Graphics/Image/Sfml/ImageSfml.h"

#include <iostream>
#include <memory>

void TestListener::OnKeyDown(const AE::OS::EventKeyboard &event)
{
	std::cout << "onKeyDown!" << std::endl;
}

void TestListener::OnKeyUp(const AE::OS::EventKeyboard &event)
{
	std::cout << "onKeyUp!" << std::endl;
}

void TestListener::OnButtonDown(const AE::OS::EventMouse &event)
{
	std::cout << "onButtonDown!" << std::endl;
}

void TestListener::OnButtonUp(const AE::OS::EventMouse &event)
{
	std::cout << "onButtonUp!" << std::endl;
}

void TestListener::OnMouseMove(const AE::OS::EventMouse &event)
{
	std::cout << "onMouseMove!" << std::endl;
}

void TestListener::BeginContact(b2Contact* contact) 
{ 
	B2_NOT_USED(contact);

	std::cout << "Contact!" << std::endl;
}

int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::Initialize();

	auto *eventManager = pluginManager->RegisterPlugin<AE::OS::EventManagerSdl>("EventSdl");
	eventManager->Install(AE::NO_OPTIONS);

	auto *windowManager = pluginManager->RegisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->Install(AE::NO_OPTIONS);

	auto *deviceManager = pluginManager->RegisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsSfml");
	deviceManager->Install(AE::NO_OPTIONS);

	auto *imageManager = pluginManager->RegisterPlugin<AE::Graphics::ImageManagerSfml>("ImageManagerSfml");
	imageManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Window Test";

	auto window = windowManager->CreateWindow(windowDesc);

	auto *deviceDriver = deviceManager->AcquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);

	auto *deviceContext = deviceDriver->CreateDeviceContext(window);

	std::unique_ptr<TestListener> testListener = std::make_unique<TestListener>();

	eventManager->RegisterWindowListener("WindowListener", testListener.get());
	eventManager->RegisterKeyListener("WindowListener", testListener.get());
	eventManager->RegisterMouseListener("WindowListener", testListener.get());

	window->Show();

	AE::OS::EventQueue *eventQueue = eventManager->GetEventQueue();

	auto image = imageManager->CreateImage("Gandalf.png");
	auto texture = deviceDriver->CreateTexture(image->GetDimensions(), image->GetData());

	b2Vec2 gravity;
	gravity.Set(0.0f, -10.0f);
	b2World *world = new b2World(gravity);
	world->SetContactListener(testListener.get());

	AE::Math::Vector2 dimensions = texture->GetDimensions();

	b2Transform transform;
	transform.Set(b2Vec2(50 + dimensions.x() / 2, 50 + dimensions.y() / 2), 0);

	b2Transform transform2;
	transform2.Set(b2Vec2(150 + dimensions.x() / 2, 50 + dimensions.y() / 2), 0);

	b2PolygonShape polygon, polygon2;
	polygon.SetAsBox(dimensions.x() / 2, dimensions.y() / 2);
	polygon2.SetAsBox(dimensions.x() / 2, dimensions.y() / 2);
	bool result = b2TestOverlap(&polygon, 0, &polygon2, 0, transform, transform2);

	while(eventQueue->PollEvents())
	{ 
		deviceContext->BeginRendering(AE::Graphics::Color(128, 0, 0, 255));

		deviceContext->DrawTexture(texture, AE::Math::Vector2(50, 50));
		deviceContext->DrawTexture(texture, AE::Math::Vector2(350, 50));
		//deviceContext->drawQuad(AE::Math::Vector2(50, 50), AE::Math::Vector2(500, 500), texture);

		deviceContext->EndRendering();
	}

	windowManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");

	eventManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");

	deviceManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsSfml");

	return 0;
}