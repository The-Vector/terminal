// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once

#include "ActionAndArgs.g.h"
#include "TerminalWarnings.h"
#include "..\inc\cppwinrt_utils.h"

namespace winrt::Microsoft::Terminal::Settings::Model::implementation
{
    struct ActionAndArgs : public ActionAndArgsT<ActionAndArgs>
    {
        static const std::map<std::string_view, ShortcutAction, std::less<>> ActionKeyNamesMap;
        static winrt::com_ptr<ActionAndArgs> FromJson(const Json::Value& json,
                                                      std::vector<Microsoft::Terminal::Settings::Model::SettingsLoadWarnings>& warnings);

        ActionAndArgs() = default;
        hstring GenerateName() const;

        GETSET_PROPERTY(Microsoft::Terminal::Settings::Model::ShortcutAction, Action, Microsoft::Terminal::Settings::Model::ShortcutAction::Invalid);
        GETSET_PROPERTY(IActionArgs, Args, nullptr);
    };
}

namespace winrt::Microsoft::Terminal::Settings::Model::factory_implementation
{
    BASIC_FACTORY(ActionAndArgs);
}
