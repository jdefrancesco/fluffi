/*
Copyright 2017-2020 Siemens AG

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without
limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

Author(s): Thomas Riedmaier
*/

#include "stdafx.h"
#include "KfuzzExtension.h"
#include "KfuzzProvider.h"

namespace Debugger::DataModel::Libraries::Kfuzz
{
	// KfuzzExtension():
	//
	// The constructor for the singleton extension class which adds new properties to "Utility"
	//
	KfuzzExtension::KfuzzExtension() :
		ExtensionModel(NamedModelParent(L"Debugger.Models.Utility"))
	{
		//
		// Add a new read-only property named "kfuzz" whose value is acquired through calling the Get_Kfuzz
		// accessor method.
		//
		AddReadOnlyProperty(L"kfuzz", this, &KfuzzExtension::Get_Kfuzz);
	}

	// Get_Kfuzz():
	//
	// The property accessor for the "kfuzz" property this extension adds to "Utility".
	Object KfuzzExtension::Get_Kfuzz(_In_ const Object& /*idk*/)
	{
		std::string buildTimeAndDate = "build on " + std::string(__DATE__) + " - " + std::string(__TIME__);
		return Object::Create(HostContext(),
			L"kfuzz extension", buildTimeAndDate,
			L"commands processed", KfuzzProvider::Get().GetNumOfProcessedCommands());
	}
}
