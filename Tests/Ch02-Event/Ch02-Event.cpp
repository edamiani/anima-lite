#include "Ch02-Event.h"

#include <iostream>
#include <memory>

void TestListener::OnAxisMove(const AE::OS::EventJoystick &event)
{
	std::cout << event.joystickId << "   " << event.axisId << "   " << event.value << std::endl;
}

void TestListener::OnButtonDown(const AE::OS::EventJoystick &event)
{
	std::cout << "Joy  button down   " << event.joystickId << "   " << event.buttonId << event.value << std::endl;
}

void TestListener::OnButtonUp(const AE::OS::EventJoystick &event)
{ 
	std::cout << "Joy  button up   " << event.joystickId << "   " << event.buttonId << std::endl;
}

void TestListener::OnHatMove(const AE::OS::EventJoystick &event)
{
	std::cout << event.joystickId << "   " << event.hatId << "   " << event.value << std::endl;
}

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

int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::Initialize();

	auto *eventManager = pluginManager->RegisterPlugin<AE::OS::EventManagerSdl>("EventSdl");
	eventManager->Install(AE::NO_OPTIONS);

	auto *windowManager = pluginManager->RegisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Event Test";

	auto window = windowManager->CreateWindow(windowDesc);

	auto testListener = std::make_unique<TestListener>();

	eventManager->RegisterWindowListener("WindowListener", testListener.get());
	eventManager->RegisterJoystickListener("JoystickListener", testListener.get());
	eventManager->RegisterKeyListener("KeyListener", testListener.get());
	eventManager->RegisterMouseListener("MouseListener", testListener.get());

	window->Show();

	AE::OS::EventQueue *eventQueue = eventManager->GetEventQueue();

	AE::MainLoop *mainLoop = new AE::MainLoop(pluginManager);
	mainLoop->Run();

	//windowManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	
	//eventManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");

	return 0;
}