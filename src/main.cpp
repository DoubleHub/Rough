/* [ ROUGH v1.0 ] */
/*
	Includes:
	- No Flash
	- Rage Aimbot
	- Slow Aim
	- Triggerbot
	- Glow ESP
	- Radar (not working)
	- Bunny Hop
	I'd like to add:
	- Skin Changer
	- Silent Aim
	- RCS
	- Box ESP
	- Bone ESP
*/

// INCLUDE SPACE =========================================
#pragma region INCLUDE SPACE
#include "EdgeLibrary.h"
#include <algorithm>
#include <thread>
using namespace EdgeLibrary;
#pragma endregion
// =======================================================

// GLOBAL DEFINE SPACE ===================================
#pragma region GLOBAL DEFINE SPACE
#define OFFSETS "C:\\RoughPublic\\Offsets.ini"
#define CONFIG "C:\\RoughPublic\\Config.ini"
#define PLAYERS 32
#define PRESSED 0x8000
#define VK_EXIT 0x70 //F1
#define VK_TOGGLE_SKINCHANGER 0x71 //F2
#define VK_TOGGLE_NOFLASH 0x72 //F3
#define VK_TOGGLE_RAGEAIMBOT 0x74 //F5
#define VK_TOGGLE_SLOWAIM 0x75 //F6
#define VK_TOGGLE_TRIGGERBOT 0x76 //F7
#define VK_TOGGLE_GLOWESP 0x77 //F8
#define VK_TOGGLE_RADAR 0x78 //F9
#define VK_TOGGLE_BHOP 0x79 //F10

#define VK_AIM 0x12 //LALT
#define VK_TRIGGER 0x04 //Mouse Middle Button
#pragma endregion
// =======================================================

// GLOBAL SCOPE ==========================================
#pragma region GLOBAL SCOPE
bool NoFlash_Toggled = false;
bool Aimbot_Toggled = false;
bool SlowAim_Toggled = false;
bool Triggerbot_Toggled = false;
bool Glow_Toggled = false;
bool Radar_Toggled = false;
bool BHop_Toggled = false;
#pragma endregion
// =======================================================

// GUI FUNCTIONS =========================================
#pragma region CONSOLE GUI

void LogConsole(std::string Message)
{
	std::cout<<"|| "<<Message<<std::endl;
}

void PrintWelcomeGUI()
{
	system("CLS");
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"||            [ ROUGH v1.0 ]          ||"<<std::endl;
	std::cout<<"||          The edge you need.        ||"<<std::endl;
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"||          Coded by Double V.        ||"<<std::endl;
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"|| TRIGGERS:			      ||"<<std::endl;
	std::cout<<"|| F2 -> Skin Changer                 ||"<<std::endl;
	std::cout<<"|| F3 -> No Flash                     ||"<<std::endl;
	std::cout<<"|| F5 -> Rage Aimbot                  ||"<<std::endl;
	std::cout<<"|| F6 -> Slow Aim                     ||"<<std::endl;
	std::cout<<"|| F7 -> Triggerbot                   ||"<<std::endl;
	std::cout<<"|| F8 -> Glow ESP                     ||"<<std::endl;
	std::cout<<"|| F9 -> Radar                        ||"<<std::endl;
	std::cout<<"|| F10 -> Bunny Hop                   ||"<<std::endl;
	std::cout<<"|| F1 -> Exit                         ||"<<std::endl;
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"|| To customize cheats go on:         ||"<<std::endl;
	std::cout<<"|| "<<CONFIG<<"          ||"<<std::endl;
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"|| To modify or update offsets go on: ||"<<std::endl;
	std::cout<<"|| "<<OFFSETS<<"         ||"<<std::endl;
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"|| CONSOLE LOG:"<<std::endl;
}

void PrintFatalError(std::string Error)
{
	system("CLS");
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"||            FATAL ERROR             ||"<<std::endl;
	std::cout<<"||       Closing in 3 seconds...      ||"<<std::endl;
	std::cout<<"|| ================================== ||"<<std::endl;
	std::cout<<"REASON:"<<std::endl;
	std::cout<<Error<<std::endl;
	Sleep(1000 * 3);
}

void SetWindow(int Width, int Height)
{
	_COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

#pragma endregion
// =======================================================

// TOGGLERS FUNCTIONS ====================================
#pragma region TOGGLERS
void NoFlashToggle()
{
	if (!NoFlash_Toggled) {
		NoFlash_Toggled = true;
		LogConsole("No Flash is now on");
	} else {
		NoFlash_Toggled = false;
		LogConsole("No Flash is now off");
	}
}
void AimbotToggle()
{
	if (!Aimbot_Toggled) {
		Aimbot_Toggled = true;
		LogConsole("Rage Aimbot is now on");
	} else {
		Aimbot_Toggled = false;
		LogConsole("Rage Aimbot is now off");
	}
}
void SlowAimToggle()
{
	if (!SlowAim_Toggled) {
		SlowAim_Toggled = true;
		LogConsole("Slow Aim is now on");
	} else {
		SlowAim_Toggled = false;
		LogConsole("Slow Aim is now off");
	}
}
void TriggerbotToggle()
{
	if (!Triggerbot_Toggled) {
		Triggerbot_Toggled = true;
		LogConsole("Triggerbot is now on");
	} else {
		Triggerbot_Toggled = false;
		LogConsole("Triggerbot is now off");
	}
}
void GlowToggle()
{
	if (!Glow_Toggled) {
		Glow_Toggled = true;
		LogConsole("Glow ESP is now on");
	} else {
		Glow_Toggled = false;
		LogConsole("Glow ESP is now off");
	}
}
void RadarToggle()
{
	if (!Radar_Toggled) {
		Radar_Toggled = true;
		LogConsole("Radar is now on");
	} else {
		Radar_Toggled = false;
		LogConsole("Radar is now off");
	}
}
void BHopToggle()
{
	if (!BHop_Toggled) {
		BHop_Toggled = true;
		LogConsole("Bunny Hop is now on");
	} else {
		BHop_Toggled = false;
		LogConsole("Bunny Hop is now off");
	}
}
void ToggleCheats()
{
	DWORD sleepms = 200;
	while (true)
	{
	if (GetAsyncKeyState(VK_TOGGLE_NOFLASH)) {
		NoFlashToggle();
		Sleep(sleepms);
	}
	if (GetAsyncKeyState(VK_TOGGLE_RAGEAIMBOT)) {
		AimbotToggle();
		Sleep(sleepms);
	}
	if (GetAsyncKeyState(VK_TOGGLE_SLOWAIM)) {
		SlowAimToggle();
		Sleep(sleepms);
	}
	if (GetAsyncKeyState(VK_TOGGLE_TRIGGERBOT)) {
		TriggerbotToggle();
		Sleep(sleepms);
	}
	if (GetAsyncKeyState(VK_TOGGLE_GLOWESP)) {
		GlowToggle();
		Sleep(sleepms);
	}
	if (GetAsyncKeyState(VK_TOGGLE_RADAR)) {
		RadarToggle();
		Sleep(sleepms);
	}
	if (GetAsyncKeyState(VK_TOGGLE_BHOP)) {
		BHopToggle();
		Sleep(sleepms);
	}
	if (GetAsyncKeyState(VK_EXIT)) {
		exit(0);
	}
	Sleep(1);
	}
}
#pragma endregion
// =======================================================

// CHEAT CODING SPACE ====================================
#pragma region CHEAT CODING SPACE

#pragma region NO FLASH

//Status:
//GREEN
//No Flash works. I don't see any particular errors for now...

#pragma region INI CONFIG
float flash_amount = (float)GetPrivateProfileIntA("NoFlash","Flash_Amount",0,CONFIG);
#pragma endregion

void NoFlash()
{
	while (true)
	{
		if (!NoFlash_Toggled) { Sleep(1); continue; }

		//Other method
		/*
		float flDuration = MemoryManager::Read<float>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_flFlashDuration);
		float flMaxAlpha = LocalPlayer::GetFlashMaxAlpha();

		if (flDuration > 0.0f && flMaxAlpha == 255.0f)
			MemoryManager::Write<float>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_flFlashMaxAlpha, 0.0f);
		else if (flMaxAlpha != 255.0f)
			MemoryManager::Write<float>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_flFlashMaxAlpha, 255.0f);
		*/

		float flDuration = MemoryManager::Read<float>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_flFlashDuration);

		if (flDuration > 0.0f)
			MemoryManager::Write<float>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_flFlashDuration, (float)flash_amount);

		Sleep(10);
	}
}

#pragma endregion

#pragma region RAGE AIMBOT

//Status:
//GREEN
//Rage Aimbot works but it needs a better way to calculate the angles

struct TargetList_t
{
	float distance;
	Vector3 AimbotAngle;

	TargetList_t(){}

	TargetList_t(Vector3 aimAngle, Vector3 myCoords, Vector3 enCoords)
	{
		distance = LibraryManager::Get3DDistance(myCoords, enCoords);
		AimbotAngle.x = aimAngle.x;
		AimbotAngle.y = aimAngle.y;
		AimbotAngle.z = aimAngle.z;
	}
};

struct CompareTargetEnArray
{
	bool operator() (TargetList_t & lhs, TargetList_t & rhs) 
	{
		return lhs.distance < rhs.distance; 
	}
};

void Aimbot()
{
	while (true)
	{
	if (!Aimbot_Toggled) { Sleep(1); continue; }

	TargetList_t* TargetList = new TargetList_t[PLAYERS];
	int targetLoop = 0;
	Vector3 AimbotAngle;

	for (int i=0; i<PLAYERS; i++)
	{
		if (Entity::GetTeam(i) == LocalPlayer::GetTeam()) continue;
		if (Entity::GetHealth(i) <= 0) continue;

		AimbotAngle = LibraryManager::NormalizeAngle(LibraryManager::CalculateAngle(LocalPlayer::GetVecOrigin(),Entity::GetFeetPosition(i)));

		TargetList[targetLoop] = TargetList_t(AimbotAngle, LocalPlayer::GetVecOrigin(), Entity::GetFeetPosition(i));
		targetLoop++;
	}

	if (targetLoop > 0)
	{
		std::sort(TargetList, TargetList + targetLoop, CompareTargetEnArray());
		//if (GetAsyncKeyState(VK_AIM)) 
		LocalPlayer::SetViewAngles(AimbotAngle);
	}
	}
}

#pragma endregion

#pragma region SLOW AIM

//Status:
//GREEN
//Slow Aim works like a charm.
//I don't see any problems for now.

void SlowAim()
{
	float LocalPlayer_Sens = LocalPlayer::GetSens();
	while (true)
	{

		if (!SlowAim_Toggled) { Sleep(1); continue; }
		
		DWORD Engine_dwBase = MemoryManager::Read<DWORD>((DWORD)Resources::EngineDLL.modBaseAddr + Offsets::m_dwClientState);
		DWORD LocalPlayer_dwBase = LocalPlayer::GetLocalPlayerBaseAddress();
		int LocalPlayer_isConnected = MemoryManager::Read<int>(Engine_dwBase + Offsets::m_dwInGame);

		if (LocalPlayer_isConnected == 6)
		{
			int LocalPlayer_CrosshairID = MemoryManager::Read<int>(LocalPlayer_dwBase + Offsets::m_iCrossHairID) - 1;
			int LocalPlayer_TeamNum = LocalPlayer::GetTeam();
			DWORD Entity_dwBase = MemoryManager::Read<DWORD>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwEntityList + (Offsets::m_dwEntityLoopDistance*LocalPlayer_CrosshairID));
			int Entity_TeamNum = MemoryManager::Read<int>(Entity_dwBase + Offsets::m_iTeamNum);
			int Entity_Health = MemoryManager::Read<int>(Entity_dwBase + Offsets::m_iHealth);

			//std::cout<<LocalPlayer_CrosshairID<<std::endl;

			if (LocalPlayer_TeamNum!=Entity_TeamNum && Entity_Health > 0)
			{
				LocalPlayer::SetSens(1.0f);
			}
			else
			{
				LocalPlayer::SetSens(LocalPlayer_Sens);
			}
		}

		Sleep(1);

	}
}

#pragma endregion

#pragma region TRIGGERBOT

//Status:
//GREEN
//Triggerbot works.
//However, I can see delay problems sometimes, but I'm not sure.

#pragma region INI CONFIG
float triggerbot_DelayBefore = (float)GetPrivateProfileIntA("Triggerbot","Delay_Before",0,CONFIG);
float triggerbot_DelayBetween = (float)GetPrivateProfileIntA("Triggerbot","Delay_Between",30,CONFIG);
float triggerbot_DelayAfter = (float)GetPrivateProfileIntA("Triggerbot","Delay_After",0,CONFIG);
#pragma endregion

void Triggerbot()
{
	while (true)
	{

		if (!Triggerbot_Toggled) { Sleep(1); continue; }
		
		DWORD Engine_dwBase = MemoryManager::Read<DWORD>((DWORD)Resources::EngineDLL.modBaseAddr + Offsets::m_dwClientState);
		DWORD LocalPlayer_dwBase = LocalPlayer::GetLocalPlayerBaseAddress();
		int LocalPlayer_isConnected = MemoryManager::Read<int>(Engine_dwBase + Offsets::m_dwInGame);

		if (LocalPlayer_isConnected == 6)
		{
			int LocalPlayer_CrosshairID = MemoryManager::Read<int>(LocalPlayer_dwBase + Offsets::m_iCrossHairID) - 1;
			int LocalPlayer_TeamNum = LocalPlayer::GetTeam();
			DWORD Entity_dwBase = MemoryManager::Read<DWORD>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwEntityList + (Offsets::m_dwEntityLoopDistance*LocalPlayer_CrosshairID));
			int Entity_TeamNum = MemoryManager::Read<int>(Entity_dwBase + Offsets::m_iTeamNum);
			int Entity_Health = MemoryManager::Read<int>(Entity_dwBase + Offsets::m_iHealth);

			//std::cout<<LocalPlayer_CrosshairID<<std::endl;

			if (LocalPlayer_TeamNum!=Entity_TeamNum && Entity_Health > 0)
			{
				LibraryManager::mouse_click(triggerbot_DelayBefore, triggerbot_DelayBetween, triggerbot_DelayAfter);
			}
		}

		Sleep(1);

	}
}

#pragma endregion

#pragma region GLOW ESP

//Status:
//GREEN
//Glow ESP works, however it needs some tweaks

#pragma region INI CONFIG
float Enemy_R = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Enemy_R"), 1, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
float Enemy_G = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Enemy_G"), 0, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
float Enemy_B = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Enemy_B"), 0, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
float Enemy_A = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Enemy_A"), 1, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
float Ally_R = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Ally_R"), 0, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
float Ally_G = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Ally_G"), 0, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
float Ally_B = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Ally_B"), 1, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
float Ally_A = (float)GetPrivateProfileInt(LibraryManager::convertCharArrayToLPCWSTR("GlowESP"), LibraryManager::convertCharArrayToLPCWSTR("Ally_A"), 1, LibraryManager::convertCharArrayToLPCWSTR(CONFIG));
#pragma endregion

void Glow()
{
	while (true)
	{

	if (!Glow_Toggled) { Sleep(1); continue; }

	DWORD dwEngineBase = LocalPlayer::GetClientState();
	int LocalPlayer_isConnected = MemoryManager::Read<int>(dwEngineBase + Offsets::m_dwInGame);

	if (LocalPlayer_isConnected == 6)
	{
		int Client_objectCount = MemoryManager::Read<int>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwGlowObject + 0x4);

		for (int i=0; i<Client_objectCount; i++)
		{
			GlowObjectPlayer_t glowObj = MemoryManager::Read<GlowObjectPlayer_t>(Client::GetGlowPointer() + (i * sizeof(GlowObjectPlayer_t)));

			if (Client::GetGlowPointer() != NULL && glowObj.pEntity != NULL)
			{
				bool EntityPlayer_isDormant = MemoryManager::Read<bool>(glowObj.pEntity + Offsets::m_bDormant);
				int EntityPlayer_TeamNum = MemoryManager::Read<int>(glowObj.pEntity + Offsets::m_iTeamNum);
				int ClassID = MemoryManager::Read<int>(MemoryManager::Read<int>(MemoryManager::Read<int>(MemoryManager::Read<int>(glowObj.pEntity + 0x8) + 2 * 0x4) + 0x1) + 20);
				if (ClassID == 35)
				{
					if (!EntityPlayer_isDormant)
					{
						if (LocalPlayer::GetTeam() != EntityPlayer_TeamNum)
						{
							//Enemy -> Color
							glowObj.r = Enemy_R; 
							glowObj.g = Enemy_G; 
							glowObj.b = Enemy_B; 
							glowObj.a = Enemy_A;
						}
						else
						{
							//Ally -> Color
							glowObj.r = Ally_R; 
							glowObj.g = Ally_G; 
							glowObj.b = Ally_B; 
							glowObj.a = Ally_A;
						}
						glowObj.RenderWhenOccluded = true;
						glowObj.RenderWhenUnoccluded = false;
						glowObj.FullBloom = false;
						MemoryManager::Write<GlowObjectPlayer_t>(Client::GetGlowPointer() + (i*sizeof(GlowObjectPlayer_t)),glowObj);
					}
				}
			}
		}

	}
	Sleep(1);
	}
}

#pragma endregion

#pragma region RADAR

//Status:
//RED
//Radar doesn't work at all.
//It seems an error in writing bSpotted...

void Radar()
{
	while (true)
	{
		if (!Radar_Toggled) { Sleep(1); continue; }

		DWORD Engine_dwBase = MemoryManager::Read<DWORD>((DWORD)Resources::EngineDLL.modBaseAddr + Offsets::m_dwClientState);
		DWORD LocalPlayer_dwBase = LocalPlayer::GetLocalPlayerBaseAddress();
		int LocalPlayer_isConnected = MemoryManager::Read<int>(LocalPlayer_dwBase + Offsets::m_dwInGame);

		if (LocalPlayer_isConnected == 6)
		{
			for (int i=0; i<PLAYERS; i++)
			{
				DWORD EntityPlayer_dwBase = Entity::GetEntityBaseAddress(i);
				int EntityPlayer_TeamNum = Entity::GetTeam(i);
				int LocalPlayer_TeamNum = LocalPlayer::GetTeam();

				if (LocalPlayer_TeamNum != EntityPlayer_TeamNum)
				{
					bool EntityPlayer_isDormant = MemoryManager::Read<bool>(EntityPlayer_dwBase + Offsets::m_bDormant);
					bool EntityPlayer_isSpotted = MemoryManager::Read<bool>(EntityPlayer_dwBase + Offsets::m_bSpotted);

					if (!EntityPlayer_isDormant && !EntityPlayer_isSpotted)
					{
						MemoryManager::Write<bool>(EntityPlayer_dwBase + Offsets::m_bSpotted, TRUE);
					}
				}
			}
		}

		Sleep(1);
	}
}

#pragma endregion

#pragma region BUNNY HOP

//Status:
//GREEN
//Bunny Hop works perfectly. I don't see any errors for now...

#pragma region INI CONFIG
int vk_bhop = GetPrivateProfileIntA("BunnyHop","Bunny_Key",VK_SPACE,CONFIG);
#pragma endregion

void BHop()
{
	while (true)
	{
		if (!BHop_Toggled) { Sleep(1); continue; }

		if (GetAsyncKeyState(vk_bhop) & PRESSED)
		{
			if (LocalPlayer::GetFlags() & (1<<0))
			{
				MemoryManager::Write<int>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwForceJump, 5);
				Sleep(20);
				MemoryManager::Write<int>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwForceJump, 4);
			}
		}

		Sleep(1);
	}
}

#pragma endregion

#pragma endregion
// =======================================================

// =======================================================
#pragma region MAIN FUNCTION

int main()
{
	if (LibraryManager::Setup("RoughPublic") != -6)
	{

	Offsets::GetOffsetsByFile(OFFSETS);

	SetConsoleTitle(LibraryManager::convertCharArrayToLPCWSTR("ROUGH v1"));
	SetWindow(40,50);
	PrintWelcomeGUI();

	//Initialize threads

	std::thread HOTKEY_thread = std::thread(ToggleCheats);
	std::thread NOFLASH_thread = std::thread(NoFlash);
	std::thread AIMBOT_thread = std::thread(Aimbot);
	std::thread SLOWAIM_thread = std::thread(SlowAim);
	std::thread TRIGGER_thread = std::thread(Triggerbot);
	std::thread GLOW_thread = std::thread(Glow);
	std::thread RADAR_thread = std::thread(Radar);
	std::thread BHOP_thread = std::thread(BHop);

	HOTKEY_thread.join();
	NOFLASH_thread.join();
	AIMBOT_thread.join();
	SLOWAIM_thread.join();
	TRIGGER_thread.join();
	GLOW_thread.join();
	RADAR_thread.join();
	BHOP_thread.join();

	}
	else PrintFatalError("Couldn't find CSGO.exe!");

	std::cout<<"Goodbye..."<<std::endl;
	return 0;
}

#pragma endregion
// =======================================================