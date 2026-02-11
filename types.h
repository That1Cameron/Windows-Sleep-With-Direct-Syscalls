typedef long NTSTATUS;
typedef void *HANDLE;
typedef unsigned long ULONG;
typedef void *PVOID;
typedef unsigned long long   ULONG_PTR;

typedef struct _IO_STATUS_BLOCK {
  union {
    NTSTATUS Status;
    PVOID    Pointer;
  };
  ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;
