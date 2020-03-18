#pragma once
#include"Hiraeth/Core/Input.h"
namespace Hiraeth
{
	class WindowsInput : public Input
	{

	private:
		virtual bool isKeyPressedPlatSpecImpl(int key) override;
		virtual bool isMouseButtonPressedPlatSpecImpl(int mouseButton) override;
		virtual std::pair<float, float> getMousePositionPlatSpecImpl() override;
		virtual float getMouseXPlatSpecImpl() override;
		virtual float getMouseYPlatSpecImpl() override;


	};
}