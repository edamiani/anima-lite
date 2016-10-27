#include "TestGraphicsDeviceAllegro.h"

#include <iostream>
#include <memory>

void TestListener::onKeyDown(const AE::OS::EventKeyboard &event)
{
	std::cout << "onKeyDown!" << std::endl;
}

void TestListener::onKeyUp(const AE::OS::EventKeyboard &event)
{
	std::cout << "onKeyUp!" << std::endl;
}

void TestListener::onButtonDown(const AE::OS::EventMouse &event)
{
	std::cout << "onButtonDown!" << std::endl;
}

void TestListener::onButtonUp(const AE::OS::EventMouse &event)
{
	std::cout << "onButtonUp!" << std::endl;
}

void TestListener::onMouseMove(const AE::OS::EventMouse &event)
{
	std::cout << "onMouseMove!" << std::endl;
}

int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::initialize();

	auto *eventManager = pluginManager->RegisterPlugin<AE::OS::EventManagerSdl>("EventSdl");
	eventManager->Install(AE::NO_OPTIONS);

	auto *windowManager = pluginManager->RegisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->Install(AE::NO_OPTIONS);

	auto *deviceManager = pluginManager->RegisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsSfml");
	deviceManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Window Test";

	auto *window = windowManager->createWindow(windowDesc);

	auto *deviceDriver = deviceManager->acquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);

	//AE::Graphics::Device::ContextDesc contextDesc;
	//contextDesc.dimensions = windowDesc.dimensions;
	auto *deviceContext = deviceDriver->createDeviceContext(window);

	std::unique_ptr<TestListener> testListener = std::make_unique<TestListener>();

	eventManager->registerWindowListener(window);
	eventManager->registerKeyListener(testListener.get());
	eventManager->registerMouseListener(testListener.get());

	window->show();

	AE::OS::EventQueue *eventQueue = eventManager->getEventQueue();

	while(eventQueue->pollEvents()) 
	{ 
		deviceContext->beginRendering(AE::Graphics::Color(128, 0, 0, 255));

		//deviceContext->drawLine(AE::Math::Vector2(10, 10), AE::Math::Vector2(200, 200), AE::Graphics::Color(0, 255, 128));

		deviceContext->endRendering();
	}

	windowManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");

	eventManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");

	deviceManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsSfml");

	return 0;
}