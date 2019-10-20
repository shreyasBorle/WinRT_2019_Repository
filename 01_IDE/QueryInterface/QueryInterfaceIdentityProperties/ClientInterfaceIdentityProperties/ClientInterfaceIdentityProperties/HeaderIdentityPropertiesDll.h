

class ISum :public IUnknown
{
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0;
};

class ISubtract :public IUnknown
{
public:
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0;
};
/*// {7ACCF1C8-8A9E-4AEA-8FF2-7B4940A675CE}
DEFINE_GUID(<<name>>, 
0x7accf1c8, 0x8a9e, 0x4aea, 0x8f, 0xf2, 0x7b, 0x49, 0x40, 0xa6, 0x75, 0xce);

*/
const CLSID CLSID_SumSubtract = { 0x7accf1c8, 0x8a9e, 0x4aea, 0x8f, 0xf2, 0x7b, 0x49, 0x40, 0xa6, 0x75, 0xce };


/*// {E065695B-E7C9-440A-8F17-51189EE40834}
DEFINE_GUID(<<name>>, 
0xe065695b, 0xe7c9, 0x440a, 0x8f, 0x17, 0x51, 0x18, 0x9e, 0xe4, 0x8, 0x34);

*/
const IID IID_ISum = { 0xe065695b, 0xe7c9, 0x440a, 0x8f, 0x17, 0x51, 0x18, 0x9e, 0xe4, 0x8, 0x34 };


/*
// {71724F9B-7FB1-4634-8DB9-02EB6C8EAEBF}
DEFINE_GUID(<<name>>,
0x71724f9b, 0x7fb1, 0x4634, 0x8d, 0xb9, 0x2, 0xeb, 0x6c, 0x8e, 0xae, 0xbf);

*/
//IID of ISubtract Interface   {994157C1-0154-478A-851E-392842AEC61F}
const IID IID_ISubtract = { 0x71724f9b, 0x7fb1, 0x4634, 0x8d, 0xb9, 0x2, 0xeb, 0x6c, 0x8e, 0xae, 0xbf };





