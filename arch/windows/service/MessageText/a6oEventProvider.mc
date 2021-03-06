; // Message Text File for armadito.
; // a6oEventProvider.mc

; // Header section

SeverityNames=(Success=0x0:STATUS_SEVERITY_SUCCESS
               Informational=0x1:STATUS_SEVERITY_INFORMATIONAL
               Warning=0x2:STATUS_SEVERITY_WARNING
               Error=0x3:STATUS_SEVERITY_ERROR
              )

LanguageNames=(English=0x409:MSG00409)

; // The following are the categories of events.

MessageIdTypedef=WORD

MessageId=0x1
SymbolicName=LIBARMADITO_CATEGORY
Language=English
Libarmadito
.

MessageId=0x2
SymbolicName=MODULES_CATEGORY
Language=English
Modules
.

MessageId=0x3
SymbolicName=SERVICE_CATEGORY
Language=English
Service
.

; // The following are the message definitions.

MessageIdTypedef=DWORD

; // Error messages
MessageId=0x100
Severity=Error
Facility=Application
SymbolicName=MSG_ERROR
Language=English
ArmaditoAV :: Error :: %1
.

; // Warning messages
MessageId=0x200
Severity=Warning
Facility=Application
SymbolicName=MSG_WARNING
Language=English
ArmaditoAV :: Warning :: %1
.

; // Information messages
MessageId=0x300
Severity=Informational
Facility=Application
SymbolicName=MSG_INFO
Language=English
ArmaditoAV :: Information :: %1
.

; // Success messages
MessageId=0x400
Severity=Success
Facility=Application
SymbolicName=MSG_SUCCESS
Language=English
ArmaditoAV :: Success :: %1
.
