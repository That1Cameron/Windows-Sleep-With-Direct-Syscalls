typedef long NTSTATUS;
typedef void *HANDLE;
typedef unsigned long ULONG;
typedef void *PVOID;
typedef unsigned long long   ULONG_PTR;
typedef unsigned char BYTE;

// structs
typedef struct _IO_STATUS_BLOCK {
  union {
    NTSTATUS Status;
    PVOID    Pointer;
  };
  ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;


typedef struct _PEB {
  BYTE                          Reserved1[2];
  BYTE                          BeingDebugged;
  BYTE                          Reserved2[1];
  PVOID                         Reserved3[2];
  PVOID                         Ldr; //PPEB_LDR_DATA
  PVOID                         ProcessParameters; //PRTL_USER_PROCESS_PARAMETERS
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
                                        void*, ULONG, void*, ULONG*);

extern "C" PEB* getPEB();

