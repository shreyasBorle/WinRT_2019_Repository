

class ISum :public IUnknown
{
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *)=0;
};

class ISubtract :public IUnknown
{
public:
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *)=0;
};
// CLSID of sumsubtract Component // {52257C6E-3538-48D2-AAB9-45FF820A9220}
const CLSID CLSID_SumSubtract = { 0x52257c6e, 0x3538, 0x48d2, 0xaa, 0xb9, 0x45, 0xff, 0x82, 0xa, 0x92, 0x20 };


//IID of ISum Interface  {FE9E87FC-ECCF-4DD6-83C2-63C6D3F83C8C}
const IID IID_ISum = { 0xfe9e87fc, 0xeccf, 0x4dd6, 0x83, 0xc2, 0x63, 0xc6, 0xd3, 0xf8, 0x3c, 0x8c };
/*
// {FE9E87FC-ECCF-4DD6-83C2-63C6D3F83C8C}
IMPLEMENT_OLECREATE(<<class>>, <<external_name>>,
0xfe9e87fc, 0xeccf, 0x4dd6, 0x83, 0xc2, 0x63, 0xc6, 0xd3, 0xf8, 0x3c, 0x8c);

*/
//IID of ISubtract Interface   {994157C1-0154-478A-851E-392842AEC61F}
const IID IID_ISubtract = { 0x994157c1, 0x154, 0x478a, 0x85, 0x1e, 0x39, 0x28, 0x42, 0xae, 0xc6, 0x1f };

/*// {994157C1-0154-478A-851E-392842AEC61F}
IMPLEMENT_OLECREATE(<<class>>, <<external_name>>, 
0x994157c1, 0x154, 0x478a, 0x85, 0x1e, 0x39, 0x28, 0x42, 0xae, 0xc6, 0x1f);
*/



