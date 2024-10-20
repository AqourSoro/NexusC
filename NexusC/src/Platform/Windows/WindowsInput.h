#pragma once

#include "NexusC/Inuput.h"

namespace nexus_c
{
	class WindowsInput: public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
	};
}