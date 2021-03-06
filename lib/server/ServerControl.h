#ifndef SERVER_CONTROL_H
#define SERVER_CONTROL_H

#include "Test.h"

bool HUPServer(int pid);
bool KillServer(int pid, bool wait_for_process = false);
bool KillServer(const std::string& pid_file, bool wait_for_process = false);
bool KillServerInternal(int pid);
int StartDaemon(int current_pid, const std::string& cmd_line, const char* pid_file, int port = 0,
	const std::string& socket_path = "");
bool StopDaemon(int current_pid, const std::string& pid_file, const std::string& memleaks_file,
	bool wait_for_process);
int LaunchServer(const std::string& rCommandLine, const char *pidFile, int port = 0,
	const std::string& socket_path = "");
int WaitForServerStartup(const char *pidFile, int pidIfKnown, int port = 0,
	const std::string& socket_path = "");

#ifdef WIN32
	#include "WinNamedPipeStream.h"
	#include "IOStreamGetLine.h"
	#include "BoxPortsAndFiles.h"

	void SetNamedPipeName(const std::string& rPipeName);
	// bool SendCommands(const std::string& rCmd);
#endif // WIN32

#endif // SERVER_CONTROL_H
