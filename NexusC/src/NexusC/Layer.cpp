#include "nxpch.h"
#include "Layer.h"

namespace nexus_c
{
	Layer::Layer(const std::string& debugName)
		:m_DebugName(debugName)
	{
	}

	/*Layer::~Layer()
	{
		
	}*/
	// replaced by 'virtual ~Layer() = default;' in Layer.h.

}
