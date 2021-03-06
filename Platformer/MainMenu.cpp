//Includes
#include <sstream>

//Custom Includes
#include "Helpers.h"
#include "MainMenu.h"
#include "Customizer.h"
#include "LevelSelect.h"
#include "CharacterSelect.h"
#include "SettingsMenu.h"
#include "Settings.h"
#include "SaveData.h"
#include "Bestiary.h"

namespace Platformer
{

	void MainMenu::Initialize(int argc, char* argv[])
	{

	}

	void MainMenu::LoadContent(int argc, char* argv[])
	{

		this->MenuFactory("./Assets/Data/Menu/Main.plMNU", Settings::AccessSettings()->MusicVolume());

	}

	void MainMenu::Update(float deltaTime)
	{

		this->MenuState::Update(deltaTime);

		if (this->inputs["StartButton"]->Value())
		{

			UI::AccessUI()->PlayConfirmEffect();

			LevelSelect* levelSelect = new LevelSelect();
			levelSelect->Initialize(0, NULL);

			char* files[2];
			files[0] = "./Saves/Levels.plLVS";
			files[1] = "./Assets/Images/LevelFrame.png";

			levelSelect->LoadContent(2, files);
			levelSelect ->SetRunning(true);

			engine.RegisterState(levelSelect);

		}

		if (this->inputs["CustomizeButton"]->Value())
		{

			UI::AccessUI()->PlayConfirmEffect();

			char* files[3];
			files[0] = "./Assets/Images/Pieces/Base";
			files[1] = "./Saves/Customization.plCTM";
			files[2] = "./Assets/Data/Spritesheet/Player.plSPS";

			Customizer* cust = new Customizer();
			cust->Initialize(0, NULL);
			cust->LoadContent(3, files);
			cust->SetRunning(true);

			engine.RegisterState(cust);

		}

		if (this->inputs["LoadButton"]->Value())
		{

			UI::AccessUI()->PlayConfirmEffect();

			char* files[3];
			files[0] = "./Assets/Images/Pieces/Base";
			files[1] = "./Saves/Customization.plCTM";
			files[2] = "./Assets/Data/Spritesheet/Player.plSPS";

			CharacterSelect* charSelect = new CharacterSelect();
			charSelect->Initialize(0, NULL);
			charSelect->LoadContent(3, files);
			charSelect->SetRunning(true);

			engine.RegisterState(charSelect);

		}

		if (this->inputs["BestiaryButton"]->Value())
		{

			UI::AccessUI()->PlayConfirmEffect();

			char* files[1];
			files[0] = "./Saves/Bestiary.plBST";

			Bestiary* best = new Bestiary();
			best->Initialize(0, NULL);
			best->LoadContent(1, files);
			best->SetRunning(true);

			engine.RegisterState(best);

		}

		if (this->inputs["OptionsButton"]->Value())
		{

			UI::AccessUI()->PlayConfirmEffect();

			SettingsMenu* settings = new SettingsMenu();
			settings->Initialize(0, NULL);
			settings->LoadContent(0, NULL);
			settings->SetRunning(true);

			engine.RegisterState(settings);

		}

		if (this->inputs["QuitButton"]->Value())
		{

			UI::AccessUI()->PlayCancelEffect();

			this->SetRunning(false);

		}

	}

	void MainMenu::Render(float deltaTime)
	{

		this->MenuState::Render(deltaTime);

		UI::AccessUI()->RenderReputation();

		UI::AccessUI()->RenderMouse();

	}

	void MainMenu::Pause()
	{

	}

	void MainMenu::Unpause()
	{

	}

	bool MainMenu::UnpauseCondition()
	{

		return true;

	}

	void MainMenu::Shutdown()
	{

	}

}