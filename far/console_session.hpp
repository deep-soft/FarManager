﻿#ifndef CONSOLE_SESSION_HPP_807900C8_23FD_4505_AEB4_B63E7AF2FF7F
#define CONSOLE_SESSION_HPP_807900C8_23FD_4505_AEB4_B63E7AF2FF7F
#pragma once

/*
console_session.hpp


*/
/*
Copyright © 2017 Far Group
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// Internal:

// Platform:

// Common:

// External:

//----------------------------------------------------------------------------

class SaveScreen;

class console_session
{
public:
	class context
	{
	public:
		NONCOPYABLE(context);

		enum class scroll_type
		{
			none,
			plugin,
			exec,
		};

		context() = default;
		~context();

		void Activate();
		void Deactivate();
		void DrawCommand(string_view Command);
		void DoPrologue();
		void DoEpilogue(scroll_type Scroll, bool IsLastInstance);
		void Consolise();
	private:
		string m_Command;
		bool m_Activated{};
		bool m_Finalised{};
		bool m_Consolised{};
	};

	void EnterPluginContext(bool Scroll);
	void LeavePluginContext(bool Scroll);
	std::shared_ptr<context> GetContext();

private:
	std::unique_ptr<SaveScreen> m_Background;
	std::weak_ptr<context> m_Context;
	std::shared_ptr<context> m_PluginContext;
	unsigned m_PluginContextInvocations{};
};

#endif // CONSOLE_SESSION_HPP_807900C8_23FD_4505_AEB4_B63E7AF2FF7F
