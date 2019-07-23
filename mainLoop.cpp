#include "cStage.h"

int main()
{
	cStage stage;
	while (true)
	{
		stage.keyClickReaction();
		stage.update();
		if (stage.isClosed())
		{
			exit(0);
		}
	}
	return 0;
}