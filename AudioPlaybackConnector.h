#pragma once

#include "resource.h"

using namespace winrt::Windows::Devices::Enumeration;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Media::Audio;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Hosting;

constexpr UINT WM_NOTIFYICON = WM_APP + 1;

HINSTANCE g_hInst;
HWND g_hWnd;
HWND g_hWndXaml;
Canvas g_xamlCanvas = nullptr;
MenuFlyout g_xamlMenu = nullptr;
FocusState g_menuFocusState = FocusState::Unfocused;
DevicePicker g_devicePicker = nullptr;
std::unordered_map<std::wstring, std::pair<DeviceInformation, AudioPlaybackConnection>> g_audioPlaybackConnections;
NOTIFYICONDATAW g_nid = {
	.cbSize = sizeof(g_nid),
	.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP | NIF_SHOWTIP,
	.uCallbackMessage = WM_NOTIFYICON,
	.uVersion = NOTIFYICON_VERSION_4
};
NOTIFYICONIDENTIFIER g_niid = {
	.cbSize = sizeof(g_niid)
};
UINT WM_TASKBAR_CREATED = 0;

#include "I18n.hpp"
