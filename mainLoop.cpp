#include "cStage.h"

int main()
{
	cStage stage;
	while (true)
	{
		stage.keyClickReaction();
		stage.obctaclesGeneration();
		stage.update();
		if (stage.isClosed())
		{
			break;
		}
	}
	return 0;
}