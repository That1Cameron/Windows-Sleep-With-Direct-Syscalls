typedef long NTSTATUS;
typedef void* HANDLE;
typedef unsigned long ULONG;
typedef unsigned long long ULONGLONG;
typedef ULONGLONG* PULONGLONG;
typedef void* PVOID;
typedef unsigned long long   ULONG_PTR;
typedef unsigned char BYTE;
typedef unsigned short USHORT;
typedef wchar_t WCHAR;
typedef WCHAR* PWSTR;

// structs a lot have been made by refrencing the types in ms docs and https://ntdoc.m417z.com/
typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR  Buffer;
} UNICODE_STRING, * PUNICODE_STRING;

typedef struct _CURDIR {
    UNICODE_STRING DosPath;
    HANDLE Handle;
} CURDIR, * PCURDIR;

typedef struct _IO_STATUS_BLOCK {
  union {
    NTSTATUS Status;
    PVOID    Pointer;
  };
  ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

//https://ntdoc.m417z.com/
typedef struct _RTL_USER_PROCESS_PARAMETERS{
    ULONG MaximumLength;
    ULONG Length;

    ULONG Flags;
    ULONG DebugFlags;

    HANDLE ConsoleHandle;
    ULONG ConsoleFlags;
    HANDLE StandardInput;
    HANDLE StandardOutput;
    HANDLE StandardError;

    CURDIR CurrentDirectory;
    UNICODE_STRING DllPath;
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    PVOID Environment;

    ULONG StartingX;
    ULONG StartingY;
    ULONG CountX;
    ULONG CountY;
    ULONG CountCharsX;
    ULONG CountCharsY;
    ULONG FillAttribute;

    ULONG WindowFlags;
    ULONG ShowWindowFlags;
    UNICODE_STRING WindowTitle;
    UNICODE_STRING DesktopInfo;
    UNICODE_STRING ShellInfo;
    UNICODE_STRING RuntimeData;
    PVOID CurrentDirectories[32];

    ULONG_PTR EnvironmentSize;
    ULONG_PTR EnvironmentVersion;

    PVOID PackageDependencyData;
    ULONG ProcessGroupId;
    ULONG LoaderThreads; // THRESHOLD
    UNICODE_STRING RedirectionDllName; // REDSTONE5
    UNICODE_STRING HeapPartitionName; // 19H1
    PULONGLONG DefaultThreadpoolCpuSetMasks;
    ULONG DefaultThreadpoolCpuSetMaskCount;
    ULONG DefaultThreadpoolThreadMaximum; // 20H1
    ULONG HeapMemoryTypeMask; // WIN11 22H2
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;


typedef struct _PEB {
  BYTE                          Reserved1[2];
  BYTE                          BeingDebugged;
  BYTE                          Reserved2[1];
  PVOID                         Reserved3[2];
  PVOID                         Ldr; //PPEB_LDR_DATA
  PRTL_USER_PROCESS_PARAMETERS  ProcessParameters; //PRTL_USER_PROCESS_PARAMETERS
  PVOID                         Reserved4[3];
  PVOID                         AtlThunkSListPtr;
  PVOID                         Reserved5;
  ULONG                         Reserved6;
  PVOID                         Reserved7;
  ULONG                         Reserved8;
  ULONG                         AtlThunkSListPtr32;
  PVOID                         Reserved9[45];
  BYTE                          Reserved10[96];
  PVOID                         PostProcessInitRoutine; //PPS_POST_PROCESS_INIT_ROUTINE
  BYTE                          Reserved11[128];
  PVOID                         Reserved12[1];
  ULONG                         SessionId;
} PEB, *PPEB;



// syscall externs
extern "C" NTSTATUS ntWriteFile_SYSCALL(HANDLE, HANDLE, void*, void*, IO_STATUS_BLOCK*,
                                        PVOID, ULONG, void*, ULONG*);

extern "C" PEB* getPEB();

