//
//  PaxEasyLinkStatusCode.h
//  PaxEasyLinkController
//
//  Created by pax on 16/8/22.
//  Copyright © 2016年 jobten. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 @abstract Return codes of EasyLink
 @discussion Please use @link  statusCode2String:@/link to transfer the return code into human readable string
 // General return codes
 @constant EL_RET_OK        Success
 @constant EL_GENERAL            General error
 @constant EL_CMD_NOT_SUPPORT       Command not supported
 @constant EL_ARG                   Argument error
 @constant EL_PROTO_CONN            Protocol connection error
 @constant EL_PROTO_SEND            Protocol send error
 @constant EL_PROTO_RECV            Protocol receive error
 @constant EL_PROTO_PACKAGE_TOO_LONG        Protocol package too long error
 @constant EL_PROTO_NO_ENOUGH_DATA          Protocol no enough data error
 @constant EL_PROTO_CHECKSUM        Protocol checksum error
 @constant EL_PROTO_DATA_FORMAT     Protocol data format error
 @constant EL_PROTO_NAKED           Protocol naked error
 @constant EL_PROTO_SYNC            Protocol sync error
 @constant EL_PROTO_NOT_CONFIRM     Protocol not confirm error
 @constant EL_PROTO_CANCEL          Protocol cancel error
 
 @constant EL_COMM_RET_BASE                     BASE COMM error start value
 @constant EL_COMM_RET_CONNECTED                Already connected
 @constant EL_COMM_RET_DISCONNECT_FAIL          COMM disconnect failed
 @constant EL_COMM_RET_NOTCONNECTED         Not connected
 @constant EL_COMM_RET_PARAM_FILE_NOT_EXIST     param file not exist
 @constant EL_COMM_RET_BUSY         Comm busy
 @constant EL_COMM_INPUT_DATA_OVERFLOW          Input data overflow
 @constant EL_COMM_READER_TAMPER            Reader tampered
 
 @constant EL_UI_RET_BASE                       BASE UI error start value
 @constant EL_UI_RET_INVALID_WIDGETNAME Invalid parameter
 @constant EL_UI_RET_TIME_OUT       Timeout
 @constant EL_UI_RET_INVALID_PAGE   Invalid page
 @constant EL_UI_RET_PARSE_UI_FAILED Parse UI failed
 @constant EL_UI_RET_VALUESIZEERROR Value size error
 @constant EL_UI_RET_INPUT_TYPE_ERROR Input type error
 @constant EL_UI_RET_INVALID_WIDGETVALUE Invalid widget value
 @constant EL_UI_RET_USER_CANCEL    User canceled
 @constant EL_UI_RET_MENUITEMNUM_ERROR      Menu item number error
 @constant EL_UI_RET_UNKOWN_ERROR   Unknown error
 @constant EL_UI_RET_GETSIGNDATA_FAIL Get signature data failed
 @constant EL_UI_RET_CARD_NUMBER_NOT_MATCH       Card number does not match
 
 @constant EL_SECURITY_RET_BASE                 BASE security error start value
 @constant EL_SECURITY_RET_NO_KEY           Key does not exist
 @constant EL_SECURITY_RET_PARAM_INVALID        Invalid parameter
 @constant EL_SECURITY_RET_ENCRYPT_DATA_ERR         Encrypt data error
 @constant EL_SECURITY_RET_GET_PIN_BLOCK_ERR        Get pin block error
 @constant EL_SECURITY_RET_NO_PIN_INPUT         No pin input
 @constant EL_SECURITY_RET_INPUT_CANCEL         User canceled
 @constant EL_SECURITY_RET_INPUT_TIMEOUT         Input timeout
 @constant EL_SECURITY_RET_KEY_TYPE_ERR         Key type error
 @constant EL_SECURITY_ERR_PED_WAIT_INTERVAL PED        wait interval
 @constant EL_SECURITY_RET_SENSITIVE_DATA_CLEARD        Sensitive data cleared
 
 @constant EL_TRANS_RET_BASE        BASE Transaction error start value
 @constant EL_TRANS_RET_ICC_RESET_ERR        ICC data reset error
 @constant EL_TRANS_RET_READ_CARD_FAIL       Read card failed
 @constant EL_TRANS_RET_CARD_BLOCKED        Card blocked
 @constant EL_TRANS_RET_EMV_RSP_ERR      Status Code returned by IC card is not 9000
 @constant EL_TRANS_RET_EMV_APP_BLOCK       The Application selected is blocked
 @constant EL_TRANS_RET_EMV_NO_APP       There is no AID matched between ICC and terminal
 @constant EL_TRANS_RET_USER_CANCELED       The Current operation or transaction was canceled by user
 @constant EL_TRANS_RET_TIME_OUT    User's operation is timeout
 @constant EL_TRANS_RET_CARD_DATA_ERROR         Data err is found
 @constant EL_TRANS_RET_TRANS_NOT_ACCEPT          Transaction is not accepted
 @constant EL_TRANS_RET_EMV_DENIAL                Transaction is denied
 @constant EL_TRANS_RET_EMV_KEY_EXP               Certification Authority Public Key is expired
 @constant EL_TRANS_RET_EMV_NO_PINPAD             PIN entry required, but PIN pad is not present or not working
 @constant EL_TRANS_RET_EMV_NO_PASSWORD           PIN entry required, PIN pad is present, but no PIN entered
 @constant EL_TRANS_RET_EMV_SUM_ERR               Checksum of CAPK is error
 @constant EL_TRANS_RET_EMV_NOT_FOUND             Appointed Data Element can't be found
 @constant EL_TRANS_RET_EMV_NO_DATA               The length of the appointed Data Element is 0
 @constant EL_TRANS_RET_EMV_OVERFLOW              Memory overflow
 @constant EL_TRANS_RET_NO_TRANS_LOG              No transaction log
 @constant EL_TRANS_RET_RECORD_NOTEXIST           Appointed log does not exist
 @constant EL_TRANS_RET_LOGITEM_NOTEXIST          Appointed Label does not exist in current log record
 @constant EL_TRANS_RET_ICC_RSP_6985              Status Code returned by IC card for GPO is 6985
 @constant EL_TRANS_RET_CLSS_USE_CONTACT          Must use other interface for the transaction
 @constant EL_TRANS_RET_EMV_FILE_ERR              File error
 @constant EL_TRANS_RET_CLSS_TERMINATE            Transaction must be terminated
 @constant EL_TRANS_RET_CLSS_FAILED               Contactless transaction failed
 @constant EL_TRANS_RET_CLSS_DECLINE              Transaction should be declined
 @constant EL_TRANS_RET_CLSS_TRY_ANOTHER_CARD     Try another card (DPAS Only)
 @constant EL_TRANS_RET_PARAM_ERR                 Parameter error
 @constant EL_TRANS_RET_CLSS_WAVE2_OVERSEA        International transaction (for VISA AP PayWave Level2 IC card use)
 @constant EL_TRANS_RET_CLSS_WAVE2_TERMINATED     Wave2 DDA response TLV format error
 @constant EL_TRANS_RET_CLSS_WAVE2_US_CARD        US card (for VISA AP PayWave L2 IC card use)
 @constant EL_TRANS_RET_CLSS_WAVE3_INS_CARD       Use IC card for the transaction (for VISA PayWave IC card use)
 @constant EL_TRANS_RET_CLSS_RESELECT_APP         Select the next AID in candidate list
 @constant EL_TRANS_RET_CLSS_CARD_EXPIRED         IC card is expired
 @constant EL_TRANS_RET_EMV_NO_APP_PPSE_ERR       No application is supported (Select PPSE error)
 @constant EL_TRANS_RET_CLSS_USE_VSDC             Switch to contactless PBOC
 @constant EL_TRANS_RET_CLSS_CVMDECLINE           CVM result in decline for AE
 @constant EL_TRANS_RET_CLSS_REFER_CONSUMER_DEVICE      Status Code returned by IC card is 6986, please see phone
 @constant EL_TRANS_RET_CLSS_LAST_CMD_ERR         Last read record command is error (qPBOC Only)
 @constant EL_TRANS_RET_CLSS_API_ORDER_ERR        APIs called in wrong order, Please call Clss_GetDebugInfo_xxx to get err codes
 @constant EL_TRANS_RET_CLSS_TORN_CARDNUM_ERR     Torn log's PAN differs from reselect card's PAN
 @constant EL_TRANS_RET_CLSS_TORN_AID_ERR         Torn log's AID differs from reselect card's AID
 @constant EL_TRANS_RET_CLSS_TORN_AMT_ERR         Torn log's amount differs from reselect card's amount
 @constant EL_TRANS_RET_CLSS_CARD_EXPIRED_REQ_ONLINE Card expired, should go online
 @constant EL_TRANS_RET_CLSS_FILE_NOT_FOUND       ICC return 6A82 (File not found) in response to the SELECT command
 @constant EL_TRANS_RET_CLSS_TRY_AGAIN            Try again (AE3.1)
 @constant EL_TRANS_RET_CLSS_REQ_JUSTTOUCH_APP    Request execution of JustTouch APP
 @constant EL_TRANS_RET_CLSS_DECRYPT_FAILED       Decrypting data failed (for JUSTOUCH)
 @constant EL_TRANS_RET_CLSS_AUTH_CONSUMER_DEVICE Authenticate with device and try again (DPAS)
 @constant EL_TRANS_RET_CLSS_UNNECESSARY_FAILED   Unnecessary function call or parameter
 @constant EL_TRANS_RET_CLSS_PAYMENT_NOT_ACCEPTED Payment type not accepted for flash
 @constant EL_TRANS_RET_CLSS_INSERTED_ICCARD      IC card detected during contactless transaction
 @constant EL_TRANS_RET_CLSS_SWIPED_MAGCARD       Magnetic stripe card detected during contactless transaction
 @constant EL_TRANS_RET_TRANS_FAILED              Transaction failed
 @constant EL_TRANS_RET_TRASN_DECLINED            Transaction declined
 @constant EL_TRANS_RET_NOT_SUPPORT               Transaction not supported
 @constant EL_TRANS_RET_EXPIRED                   Card expired
 @constant EL_TRANS_RET_LUHN_ERR                  Luhn error
 @constant EL_TRANS_RET_LUHN_NO_CARD              No card number error (Luhn check)
 
 @constant EL_FILEDOWNLOAD_ERR_BASE					  BASE filedownload error start value
 @constant EL_FILEDOWNLOAD_ERR_INVALID_PARAM		      invalid parameter
 @constant EL_FILEDOWNLOAD_ERR_DOWNLOAD_FILE_FAIL	  Download parameter file failed
 @consatnt EL_FILEDOWNLOAD_RET_FIRMWARE_FAIL           Download firmware/app/font failed
 @constant EL_FILEDOWNLOAD_ERR_FILE_OVERSIZE			  File over size
 @constant EL_FILEDOWNLOAD_ERR_PARSE_ERR				  Parse file failed
 @constant  EL_FILEDOWNLOAD_RET_SIGN_ERR                File signature error
 
 @constant EL_PARAM_RET_BASE                          Base return code for parameter management module
 @constant EL_PARAM_RET_ERR_DATA                      Input data error.
 @constant EL_PARAM_RET_INVALID_PARAM                 Invalid parameter.
 @constant EL_PARAM_RET_PARTIAL_FAILED                Partial operation failed.
 @constant EL_PARAM_RET_ALL_FAILED                    All operation failed.
 @constant EL_PARAM_RET_BUFFER_TOO_SMALL             the output buffer size is not enough.
 @constant EL_PARAM_RET_API_ORDER_ERR                 Must call this function after StartTransation step
 @constant EL_PARAM_RET_ENCRYPT_SENSITIVE_DATA_FAILED encrypted sensitive data failed
 EL_PARAM_RET_SET_CONFIG_TLV_CMD_ERROR        SetDatatCmd(config tlv data) failed
 EL_PARAM_RET_SET_EMV_TLV_CMD_ERROR           SetDatatCmd(emv tlv data) failed"
 EL_PARAM_RET_UNSUPPORT_CARD                Unsupport card
 
 @constant EL_SDK_RET_BASE                            Base return code for SDK
 @constant EL_SDK_RET_PARAM_INVALID                   invalid param
 @constant EL_SDK_RET_COMM_CONNECT_ERR                comm connect err
 @constant EL_SDK_RET_COMM_DISCONNECT_ERR             comm disconnect err
 @constant EL_SDK_RET_COMM_DISCONNECTED               comm disconnected
 @constant EL_SDK_RET_COMM_SEND_ERR                   comm sent err
 @constant EL_SDK_RET_COMM_RECV_ERR                   comm recv err
 @constant EL_SDK_RET_FILE_NOT_EXIST                    File does not exist
 @constant EL_SDK_RET_GET_DATA_FAIL                     Get data failed
 @constant EL_SDK_RET_BT_NOT_ENABLED                    Bluetooth is not enable
 @constant EL_SDK_RET_ENC_SESSION_KEY_DEC_ERR           Encrypted session key dec error
 
 @constant EL_SDK_PROTO_RET_BASE                      Base return code for proto err
 @constant EL_SDK_RET_PROTO_GENERAL_ERR               general error
 @constant EL_SDK_RET_PROTO_ARG_ERR                   argument error
 @constant EL_SDK_RET_PROTO_PACKET_TOO_LONG           packet too long
 @constant EL_SDK_RET_PROTO_NO_ENOUGH_DATA            receive data not enough
 @constant EL_SDK_RET_PROTO_DATA_FORMAT               data format error
 @constant EL_SDK_RET_PROTO_TIMEOUT timeout           timeout
 
 @constant EL_RKI_RET_BASE      Base return code for RKI err
 @constant EL_RKI_RET_BIND_PHASE_ONE           Bind1
 @constant EL_RKI_RET_BIND_PHASE_TWO           Bind2
 @constant EL_RKI_RET_REBIND_PHASE_ONE         Rebind1
 @constant EL_RKI_RET_REBIND_PHASE_TWO         Rebind2
 @constant EL_RKI_RET_DOWNLOAD_PHASE_ONE       DWLoad1
 @constant EL_RKI_RET_DOWNLOAD_PHASE_TWO       DWLoad2
 @constant EL_RKI_RET_PARAM_NULL_ERR           Para Err
 @constant EL_RKI_RET_INIT_ERR                 Init Err
 @constant EL_RKI_RET_COMM_ERR                 Comm Err
 @constant EL_RKI_RET_CONSTRUCT_TLV_ERR        Comm Err
 @constant EL_RKI_RET_GET_DEVICE_INFO_ERR      Get DID Err
 @constant EL_RKI_RET_GET_DA_CERT_ERR          Read PUK Err
 @constant EL_RKI_RET_GET_DE_CERT_ERR          Read PUK Err
 @constant EL_RKI_RET_GET_RKI_INFO_ERR         Read Info Err
 @constant EL_RKI_RET_PARSE_TLV_ERR            Comm Err
 @constant EL_RKI_RET_SERVICE_REJECT           Sys Reject
 @constant EL_RKI_RET_SERVER_CERT_EXPIRE       Cert Expired
 @constant EL_RKI_RET_SERVER_CLOSE_ERR         Close Server Err
 @constant EL_RKI_RET_GEN_DE_AUTH_DATA_ERR     Term Auth Err
 @constant EL_RKI_RET_GET_AUTH_DATA_ERR        Term Auth Err
 @constant EL_RKI_RET_CERT_INFO_ERR            Read Cert Err
 @constant EL_RKI_RET_WRITE_AUTH_KEY_ERR       Server Cert Err
 @constant EL_RKI_RET_DE_AUTH_TOKEN_ERR        Device Token Err
 @constant EL_RKI_RET_WRITE_KMS_ID_ERR         Term Status Err
 @constant EL_RKI_RET_VERIFY_PUK_ERR           Server Cert Err
 @constant EL_RKI_RET_INJECT_KEY_ERR           Inject Key Err
 @constant EL_RKI_RET_PINPAD_PROTOCOL_ERR      PED protocol Err
 @constant EL_RKI_RET_PINPAD_INIT_ERR          PED init Err
 @constant EL_RKI_RET_UNBIND_WRITE_KEY_LIST_ERR Key List Err
 @constant EL_RKI_RET_UNBIND_PHASE_ONE         Unbind1
 @constant EL_RKI_RET_UNBIND_PHASE_TWO         Unbind2
 @constant EL_RKI_RET_INJECT_OFFLINE_KEY       Offline Key
 @constant EL_RKI_RET_OFFLINE_KEY_ERR          Key File Err
 @constant EL_RKI_RET_OFFLINE_KEY_TOO_LONG     File Too Long
 @constant EL_RKI_RET_END                      System Err
 @constant EL_RKI_SERVER_RET_COMM_TIMEOUT           DHCP Err
 @constant EL_RKI_SERVER_RET_COMM_NET_ERR           Connect Err
 @constant EL_RKI_SERVER_RET_COMM_DISCONNECTED      Connect Err
 @constant EL_RKI_SERVER_RET_COMM_NOT_CONNECT       Connect Err
 @constant EL_RKI_SERVER_RET_COMM_SEND_ERR          Send Err
 @constant EL_RKI_SERVER_RET_COMM_RECV_ERR          Recv Err
 @constant EL_RKI_SERVER_RET_PARAM_INVALID          Comm Para Err
 @constant EL_RKI_SERVER_RET_COMM_CONNECT_ERR           SSL Connect Err
 @constant EL_RKI_SERVER_RET_SSL_CERT_ERR               SSL Cert Err
 
 @constant EL_SML_RET_BASE                  Base return code for Smartlanding err
 @constant EL_SML_DB_SAVE_ERROR                 Database save error
 @constant EL_SML_DB_OPEN_ERROR                 Database open error
 @constant EL_SML_COMM_NO_CERT                  Comm no cert.
 @constant EL_SML_COMM_DNS_ERROR                Comm DNS error.
 @constant EL_SML_COMM_SEND_ERR                 Comm send error.
 @constant EL_SML_COMM_RECV_ERR                 Comm receive error.
 @constant EL_SML_COMM_NEW_SSL_CTX_ERR          Comm error in creating new SSL context.
 @constant EL_SML_COMM_CREATE_SOCKET_ERR        Comm error in creating socket.
 @constant EL_SML_COMM_SET_SOCKET_OPT_ERR       Comm error in setting socket option.
 @constant EL_SML_COMM_CONNECT_ERR              Comm connect error.
 @constant EL_SML_PACK_PARAM_ERR                Pack parameters error.
 @constant EL_SML_PACK_TYPE_NOT_SUPPORT         Pack type not supported.
 @constant EL_SML_UNPACK_FORMAT                 Format error after unpack.
 @constant EL_SML_UNPACK_LRC                    Unpack LRC error.
 @constant EL_SML_DEVICE_OPEN_ERR               Device open error.
 @constant EL_SML_DEVICE_CONFIG_ERR             Device config error.
 @constant EL_SML_COMM_PARAM_ERR                Comm param error.
 @constant EL_SML_NOT_SUPPORT_RKI_COM           RKI comm param not supported.
 @constant EL_SML_EVN_CHECK_ERR                 Environment check error.
 @constant EL_SML_EVN_CLEAR_TASK_ERR            Clear task error.
 @constant EL_SML_SERVER_ERR                    Server error.
 @constant EL_SML_DOWNLOAD_ERR                  Download error.
 @constant EL_SML_DOWNLOAD_MD5_ERR              Download MD5 error.
 @constant EL_SML_RET_COMM_HOST_ERROR           Fail to connect with Host URL
 @constant EL_SML_RET_SYNC_ERROR                Sync task error
 @constant EL_SML_RET_PROCESS_ERROR             Process task error
 @constant EL_SML_RET_APP_INSTALL_ERROR         Install app error
 @constant EL_SML_RET_RKI_DOWNLOAD_ERROR        RKI download error
 @constant EL_SML_RET_INVALID_DOWNLOAD_FILE     Invalid download file
 @constant EL_SML_RET_TERMINAL_NOT_REGISTER     Terminal not registered, need TID
 @constant EL_SML_USER_CANCEL                   User cancel
 
 @constant EL_PICC_BASE                  Base return code for PICC err
 @constant EL_PICC_PARAM_ERROR                 Picc Parameter error
 @constant EL_PICC_RF_MODULE_CLOSE             RF module close
 @constant EL_PICC_NO_SPECIFIC_CARD_IN_AREA    No specific card in sensing area
 @constant EL_PICC_TOO_MUCH_CARD_IN_AREA       Too much card in sensing area (communication conflict)
 @constant EL_PICC_RESP_PROTOCOL_ERROR         Protocol error (data response from card breaches the agreement)
 @constant EL_PICC_CARD_NOT_ACTIVATED          Card not activated
 @constant EL_PICC_MULTI_CARD_CONFLICT         Multi-card conflict
 @constant EL_PICC_NO_RESPONSE_TIMEOUT         No response timeout
 @constant EL_PICC_PROTOCOL_ERROR              Protocol error
 @constant EL_PICC_COMM_TRANSMIT_ERROR         Communication transmission error
 @constant EL_PICC_M1_CARD_AUTH_FAIL           M1 Card authentication failure
 @constant EL_PICC_SECTOR_NOT_CERTIFIED        Sector is not certified
 @constant EL_PICC_DATA_FORMAT_INCORRECT       The data format of value block is incorrect
 @constant EL_PICC_CARD_STILL_IN_AREA          Card is still in sensing area
 @constant EL_PICC_CARD_STATUS_ERROR           Card status error (e.g., A/B card calling M1 interface)
 @constant EL_PICC_INTERFACE_CHIP_ERROR        Interface chip does not exist or is abnormal
 @constant EL_PICC_PAR_FLAG                    Parity error
 @constant EL_PICC_CRC_FLAG                    CRC error
 @constant EL_PICC_ECD_FLAG                    Frame format error
 @constant EL_PICC_EMD_FLAG                    Interference
 @constant EL_PICC_PARAMFILE_FLAG              Configuration file does not exist
 @constant EL_PICC_USER_CANCEL                 Transaction is cancelled
 @constant EL_PICC_CARRIER_OBTAIN_FLAG         No obtained carrier
 @constant EL_PICC_CONFIG_FLAG                 Fail to configure register
 @constant EL_PICC_RXLEN_EXCEED_FLAG           Returned data length exceeds set receiving length
 @constant EL_PICC_NOT_IDLE_FLAG               Card is not in idle state
 @constant EL_PICC__NOT_POLLING_FLAG           No polling
 @constant EL_PICC_NOT_WAKEUP_FLAG             Card does not wakeup
 @constant EL_PICC_NOT_SUPPORT                 Chip is unsupported
 @constant EL_PICC_BATTERY_VOLTAGE_TOO_LOW     Battery voltage is too low
 @constant EL_PICC_CHIP_ERROR                  Chip card error

 @constant EL_MSR_BASE                  Base return code for MSR err
 @constant EL_MSR_RET_FAILED                  Fail to operate MSR
 @constant EL_MSR_RET_HEADE                   Head mark is not found
 @constant EL_MSR_RET_END                     End mark is not found
 @constant EL_MSR_RET_LRC                     LRC check error
 @constant EL_MSR_RET_PAR                     Check error of a certain bit of MSR
 @constant EL_MSR_RET_NOT_SWIPED              No polling
 @constant EL_MSR_RET_NO_DATA                 No card is swiped
 @constant EL_MSR_END_RET_ZERO              Magnetic stripe card format error.
 @constant EL_MSR_PED_RET_DECRYPT             PED decryption failed
 @constant EL_MSR_RET_NO_TRACK                The corresponding magnetic track is missing
 
 @constant EL_ICC_BASE                  Base return code for ICC err
 @constant EL_ICC_RET_SCI_HW_NOCARD                No card
 @constant EL_ICC_RET_SCI_HW_STEP                  No initialization when exchanging data; no power when warm resetting
 @constant EL_ICC_RET_SCI_HW_PARITY                Parity check error
 @constant EL_ICC_RET_SCI_HW_TIMEOUT               Timeout
 @constant EL_ICC_RET_SCI_TCK                      TCK error
 @constant EL_ICC_RET_SCI_ATR_TS                   ATR TS error
 @constant EL_ICC_RET_SCI_ATR_TA1                  ATR TA1 error
 @constant EL_ICC_RET_SCI_ATR_TD1                  ATR TD1 error
 @constant EL_ICC_RET_SCI_ATR_TA2                  ATR TA2 error
 @constant EL_ICC_RET_SCI_ATR_TB1                  ATR TB1 error
 @constant EL_ICC_RET_SCI_ATR_TB2                  ATR TB2 error
 @constant EL_ICC_RET_SCI_ATR_TC2                  ATR TC2 error
 @constant EL_ICC_RET_SCI_ATR_TD2                  ATR TD2 error
 @constant EL_ICC_RET_SCI_ATR_TA3                  ATR TA3 error
 @constant EL_ICC_RET_SCI_ATR_TB3                  ATR TB3 error
 @constant EL_ICC_RET_SCI_ATR_TC3                  ATR TC3 error
 @constant EL_ICC_RET_SCI_T_ORDER                  Protocol is not T0 or T1
 @constant EL_ICC_RET_SCI_PPS_PPSS                 PPSS error in PPS
 @constant EL_ICC_RET_SCI_PPS_PPS0                 PPS0 error in PPS
 @constant EL_ICC_RET_SCI_PPS_PCK                  ATRPCK error in PPS
 @constant EL_ICC_RET_SCI_T0_PARAM                 Transmitted data is too long in T0
 @constant EL_ICC_RET_SCI_T0_REPEAT                Too many character repetitions in T0
 @constant EL_ICC_RET_SCI_T0_PROB                  Procedure byte error in T0
 @constant EL_ICC_RET_SCI_T1_PARAM                 Transmitted data is too long in T1
 @constant EL_ICC_RET_SCI_T1_BWT                   BWT is oversize in T1
 @constant EL_ICC_RET_SCI_T1_CWT                   CWT is oversize in T1
 @constant EL_ICC_RET_SCI_T1_BREP                  Too many block repetitions in T1
 @constant EL_ICC_RET_SCI_T1_LRC                   LRC error in T1
 @constant EL_ICC_RET_SCI_T1_NAD                   NAD error in T1
 @constant EL_ICC_RET_SCI_T1_LEN                   LEN error in T1
 @constant EL_ICC_RET_SCI_T1_PCB                   PCB error in T1
 @constant EL_ICC_RET_SCI_T1_SRC                   SRC error in T1
 @constant EL_ICC_RET_SCI_T1_SRL                   SRL error in T1
 @constant EL_ICC_RET_SCI_T1_SRA                   SRA error in T1
 @constant EL_ICC_RET_SCI_PARAM                    Invalid parameter
 @constant EL_ICC_RET_SCI_OTHER_ERROR              Other error
 @constant EL_ICC_RET_SCI_CHANNEL                  Card channel error
 @constant EL_ICC_RET_SCI_DATA_LEN                 Data length error
 @constant EL_ICC_RET_SCI_T1_ABORT                 Abort comm error in T1
 @constant EL_ICC_RET_SCI_T1_EDC                   EDC error in T1
 @constant EL_ICC_RET_SCI_T1_SYNC                  SYNC error in T1
 @constant EL_ICC_RET_SCI_T1_EG                    EG error in T1
 @constant EL_ICC_RET_SCI_T1_BG                    BG error in T1
 @constant EL_ICC_RET_SCI_T1_IFSC                  IFSC error in T1
 @constant EL_ICC_RET_SCI_T1_IFSD                  IFSD error in T1
 @constant EL_ICC_RET_SCI_CHAR_GROUP_INVALID       Character group invalid
 @constant EL_ICC_RET_SCI_ATR_TC1                  ATR TC1 error
 @constant EL_ICC_RET_SCI_ATR_DATA_LEN             ATR data length error
 @constant EL_ICC_RET_SCI_T0_TIMEOUT               Timeout in T0
 @constant EL_ICC_RET_SCI_T0_RESENT                Re-send error in T0
 @constant EL_ICC_RET_SCI_T0_RECEIVE               Re-receive error in T0
 @constant EL_ICC_RET_SCI_T0_STATUS_BYTE_INVALID   Status byte error
 @constant EL_ICC_RET_SCI_RE_CHAR_GROUP            Re-send/receive character group error
 @constant EL_ICC_RET_SCI_COMM_ERROR               Card communication error
 */

typedef enum {
    
    EL_RET_OK                               = 0,
    EL_COMM_ERROR                           = -1,
    EL_CMD_NOT_SUPPORT                      = 0x9999,
    EL_GENERAL                              = -1,
    EL_ARG                                  = -2,
    EL_PROTO_CONN                           = -100,
    EL_PROTO_SEND                           = -101,
    EL_PROTO_RECV                           = -102,
    EL_PROTO_PACKAGE_TOO_LONG               = -103,
    EL_PROTO_NO_ENOUGH_DATA                 = -104,
    EL_PROTO_CHECKSUM                       = -105,
    EL_PROTO_DATA_FORMAT                    = -106,
    EL_PROTO_NAKED                          = -107,
    EL_PROTO_SYNC                           = -108,
    EL_PROTO_NOT_CONFIRM                    = -109,
    EL_PROTO_CANCEL                         = -110,
    
    EL_COMM_RET_BASE                       = 1000,
    EL_COMM_RET_CONNECTED                  = (EL_COMM_RET_BASE +1),
    EL_COMM_RET_DISCONNECT_FAIL            = (EL_COMM_RET_BASE +2),
    EL_COMM_RET_NOTCONNECTED               = (EL_COMM_RET_BASE +3),
    EL_COMM_RET_PARAM_FILE_NOT_EXIST       = (EL_COMM_RET_BASE + 4),
    EL_COMM_RET_BUSY                       = (EL_COMM_RET_BASE + 5),
    EL_COMM_INPUT_DATA_OVERFLOW            = (EL_COMM_RET_BASE + 6),
    EL_COMM_READER_TAMPER                  = (EL_COMM_RET_BASE + 7),
    
    
    EL_UI_RET_BASE						    =(2000),
    EL_UI_RET_INVALID_WIDGETNAME		    =(EL_UI_RET_BASE + 1),
    EL_UI_RET_TIME_OUT					    =(EL_UI_RET_BASE + 2),
    EL_UI_RET_INVALID_PAGE			        =(EL_UI_RET_BASE +3),
    EL_UI_RET_PARSE_UI_FAILED			    =(EL_UI_RET_BASE +4),
    EL_UI_RET_VALUESIZEERROR			    =(EL_UI_RET_BASE +5),
    EL_UI_RET_INPUT_TYPE_ERROR 		        =(EL_UI_RET_BASE + 6),
    EL_UI_RET_INVALID_WIDGETVALUE 	        =(EL_UI_RET_BASE + 7),
    EL_UI_RET_USER_CANCEL				    =(EL_UI_RET_BASE + 8),
    EL_UI_RET_MENUITEMNUM_ERROR		        =(EL_UI_RET_BASE + 9),
    EL_UI_RET_UNKOWN_ERROR                  =(EL_UI_RET_BASE + 10),
    EL_UI_RET_GETSIGNDATA_FAIL              =(EL_UI_RET_BASE + 11),
    EL_UI_RET_CARD_NUMBER_NOT_MATCH         =(EL_UI_RET_BASE + 12),
    
    EL_SECURITY_RET_BASE					=3000,
    EL_SECURITY_RET_NO_KEY					=(EL_SECURITY_RET_BASE + 1),
    EL_SECURITY_RET_PARAM_INVALID			=(EL_SECURITY_RET_BASE + 2),
    EL_SECURITY_RET_ENCRYPT_DATA_ERR		=(EL_SECURITY_RET_BASE + 3),
    EL_SECURITY_RET_GET_PIN_BLOCK_ERR		=(EL_SECURITY_RET_BASE + 4),
    EL_SECURITY_RET_NO_PIN_INPUT			=(EL_SECURITY_RET_BASE + 5),
    EL_SECURITY_RET_INPUT_CANCEL			=(EL_SECURITY_RET_BASE + 6),
    EL_SECURITY_RET_INPUT_TIMEOUT			=(EL_SECURITY_RET_BASE + 7),
    EL_SECURITY_RET_KEY_TYPE_ERR            =(EL_SECURITY_RET_BASE + 8),
    EL_SECURITY_ERR_PED_WAIT_INTERVAL       =(EL_SECURITY_RET_BASE + 9),
    EL_SECURITY_RET_SENSITIVE_DATA_CLEARD   =(EL_SECURITY_RET_BASE + 10),
    
    EL_WRITE_KEY_RET_BASE                   = 3110,
    EL_WRITE_KEY_NO_KEY                     = (EL_WRITE_KEY_RET_BASE+1),
    EL_WRITE_KEY_KEYIDX_ERR                 = (EL_WRITE_KEY_RET_BASE+2),
    EL_WRITE_KEY_DERIVE_ERR                 = (EL_WRITE_KEY_RET_BASE+3),
    EL_WRITE_KEY_CHECK_KEY_FAIL             = (EL_WRITE_KEY_RET_BASE+4),
    EL_WRITE_KEY_NO_PIN_INPUT               = (EL_WRITE_KEY_RET_BASE+5),
    EL_WRITE_KEY_INPUT_CANCEL               = (EL_WRITE_KEY_RET_BASE+6),
    EL_WRITE_KEY_WAIT_INTERVAL              = (EL_WRITE_KEY_RET_BASE+7),
    EL_WRITE_KEY_CHECK_MODE_ERR             = (EL_WRITE_KEY_RET_BASE+8),
    EL_WRITE_KEY_NO_RIGHT_USE               = (EL_WRITE_KEY_RET_BASE+9),
    EL_WRITE_KEY_KEY_TYPE_ERR               = (EL_WRITE_KEY_RET_BASE+10),
    EL_WRITE_KEY_EXPLEN_ERR                 = (EL_WRITE_KEY_RET_BASE+11),
    EL_WRITE_KEY_DSTKEY_IDX_ERR             = (EL_WRITE_KEY_RET_BASE+12),
    EL_WRITE_KEY_SRCKEY_IDX_ERR             = (EL_WRITE_KEY_RET_BASE+13),
    EL_WRITE_KEY_KEY_LEN_ERR                = (EL_WRITE_KEY_RET_BASE+14),
    EL_WRITE_KEY_INPUT_TIMEOUT              = (EL_WRITE_KEY_RET_BASE+15),
    EL_WRITE_KEY_NO_ICC                     = (EL_WRITE_KEY_RET_BASE+16),
    EL_WRITE_KEY_CC_NO_INIT                 = (EL_WRITE_KEY_RET_BASE+17),
    EL_WRITE_KEY_GROUP_IDX_ERR              = (EL_WRITE_KEY_RET_BASE+18),
    EL_WRITE_KEY_PARAM_PTR_NULL             = (EL_WRITE_KEY_RET_BASE+19),
    EL_WRITE_KEY_LOCKED                     = (EL_WRITE_KEY_RET_BASE+20),
    EL_WRITE_KEY_ERROR                      = (EL_WRITE_KEY_RET_BASE+21),
    EL_WRITE_KEY_NOMORE_BUF                 = (EL_WRITE_KEY_RET_BASE+22),
    EL_WRITE_KEY_NEED_ADMIN                 = (EL_WRITE_KEY_RET_BASE+23),
    EL_WRITE_KEY_DUKPT_OVERFLOW             = (EL_WRITE_KEY_RET_BASE+24),
    EL_WRITE_KEY_KCV_CHECK_FAIL             = (EL_WRITE_KEY_RET_BASE+25),
    EL_WRITE_KEY_SRCKEY_TYPE_ERR            = (EL_WRITE_KEY_RET_BASE+26),
    EL_WRITE_KEY_UNSPT_CMD                  = (EL_WRITE_KEY_RET_BASE+27),
    EL_WRITE_KEY_COMM_ERR                   = (EL_WRITE_KEY_RET_BASE+28),
    EL_WRITE_KEY_NO_UAPUK                   = (EL_WRITE_KEY_RET_BASE+29),
    EL_WRITE_KEY_ADMIN_ERR                  = (EL_WRITE_KEY_RET_BASE+30),
    EL_WRITE_KEY_DOWNLOAD_INACTIVE          = (EL_WRITE_KEY_RET_BASE+31),
    EL_WRITE_KEY_KCV_ODD_CHECK_FAIL         = (EL_WRITE_KEY_RET_BASE+32),
    EL_WRITE_KEY_PED_DATA_RW_FAIL           = (EL_WRITE_KEY_RET_BASE+33),
    EL_WRITE_KEY_ICC_CMD_ERR                = (EL_WRITE_KEY_RET_BASE+34),
    EL_WRITE_KEY_INPUT_CLEAR                = (EL_WRITE_KEY_RET_BASE+39),
    EL_WRITE_KEY_NO_FREE_FLASH              = (EL_WRITE_KEY_RET_BASE+43),
    EL_WRITE_KEY_DUKPT_NEED_INC_KSN         = (EL_WRITE_KEY_RET_BASE+44),
    EL_WRITE_KEY_KCV_MODE_ERR               = (EL_WRITE_KEY_RET_BASE+45),
    EL_WRITE_KEY_DUKPT_NO_KCV               = (EL_WRITE_KEY_RET_BASE+46),
    EL_WRITE_KEY_PIN_BYPASS_BYFUNKEY        = (EL_WRITE_KEY_RET_BASE+47),
    EL_WRITE_KEY_MAC_ERR                    = (EL_WRITE_KEY_RET_BASE+48),
    EL_WRITE_KEY_CRC_ERR                    = (EL_WRITE_KEY_RET_BASE+49),
    EL_WRITE_KEY_PARAM_INVALID              = (EL_WRITE_KEY_RET_BASE+50),
    
    
    EL_TRANS_RET_BASE						    = 4000,
    EL_TRANS_RET_ICC_RESET_ERR                  =(EL_TRANS_RET_BASE + 1),
    EL_TRANS_RET_READ_CARD_FAIL                 =(EL_TRANS_RET_BASE + 2),
    EL_TRANS_RET_CARD_BLOCKED                   =(EL_TRANS_RET_BASE + 3),
    EL_TRANS_RET_EMV_RSP_ERR                    =(EL_TRANS_RET_BASE + 4),
    EL_TRANS_RET_EMV_APP_BLOCK                  =(EL_TRANS_RET_BASE + 5),
    EL_TRANS_RET_EMV_NO_APP                     =(EL_TRANS_RET_BASE + 6),
    EL_TRANS_RET_USER_CANCELED                  =(EL_TRANS_RET_BASE + 7),
    EL_TRANS_RET_TIME_OUT                       =(EL_TRANS_RET_BASE + 8),
    EL_TRANS_RET_CARD_DATA_ERROR                =(EL_TRANS_RET_BASE + 9),
    EL_TRANS_RET_TRANS_NOT_ACCEPT               =(EL_TRANS_RET_BASE + 10),
    EL_TRANS_RET_EMV_DENIAL                     =(EL_TRANS_RET_BASE + 11),
    EL_TRANS_RET_EMV_KEY_EXP                    =(EL_TRANS_RET_BASE + 12),
    EL_TRANS_RET_EMV_NO_PINPAD                  =(EL_TRANS_RET_BASE + 13),
    EL_TRANS_RET_EMV_NO_PASSWORD                =(EL_TRANS_RET_BASE + 14),
    EL_TRANS_RET_EMV_SUM_ERR                    =(EL_TRANS_RET_BASE + 15),
    EL_TRANS_RET_EMV_NOT_FOUND                  =(EL_TRANS_RET_BASE + 16),
    EL_TRANS_RET_EMV_NO_DATA                    =(EL_TRANS_RET_BASE + 17),
    EL_TRANS_RET_EMV_OVERFLOW                   =(EL_TRANS_RET_BASE + 18),
    EL_TRANS_RET_NO_TRANS_LOG                   =(EL_TRANS_RET_BASE + 19),
    EL_TRANS_RET_RECORD_NOTEXIST                =(EL_TRANS_RET_BASE + 20),
    EL_TRANS_RET_LOGITEM_NOTEXIST               =(EL_TRANS_RET_BASE + 21),
    EL_TRANS_RET_ICC_RSP_6985                   =(EL_TRANS_RET_BASE + 22),
    EL_TRANS_RET_CLSS_USE_CONTACT               =(EL_TRANS_RET_BASE + 23),
    EL_TRANS_RET_EMV_FILE_ERR                   =(EL_TRANS_RET_BASE + 24),
    EL_TRANS_RET_CLSS_TERMINATE                 =(EL_TRANS_RET_BASE + 25),
    EL_TRANS_RET_CLSS_FAILED                    =(EL_TRANS_RET_BASE + 26),
    EL_TRANS_RET_CLSS_DECLINE                   =(EL_TRANS_RET_BASE + 27),
    EL_TRANS_RET_CLSS_TRY_ANOTHER_CARD          =(EL_TRANS_RET_BASE + 28),
    EL_TRANS_RET_PARAM_ERR                      =(EL_TRANS_RET_BASE + 30),
    EL_TRANS_RET_CLSS_WAVE2_OVERSEA             =(EL_TRANS_RET_BASE + 31),
    EL_TRANS_RET_CLSS_WAVE2_TERMINATED          =(EL_TRANS_RET_BASE + 32),
    EL_TRANS_RET_CLSS_WAVE2_US_CARD             =(EL_TRANS_RET_BASE + 33),
    EL_TRANS_RET_CLSS_WAVE3_INS_CARD            =(EL_TRANS_RET_BASE + 34),
    EL_TRANS_RET_CLSS_RESELECT_APP              =(EL_TRANS_RET_BASE + 35),
    EL_TRANS_RET_CLSS_CARD_EXPIRED              =(EL_TRANS_RET_BASE + 36),
    EL_TRANS_RET_EMV_NO_APP_PPSE_ERR            =(EL_TRANS_RET_BASE + 37),
    EL_TRANS_RET_CLSS_USE_VSDC                  =(EL_TRANS_RET_BASE + 38),
    EL_TRANS_RET_CLSS_CVMDECLINE                =(EL_TRANS_RET_BASE + 39),
    EL_TRANS_RET_CLSS_REFER_CONSUMER_DEVICE     =(EL_TRANS_RET_BASE + 40),
    EL_TRANS_RET_CLSS_LAST_CMD_ERR              =(EL_TRANS_RET_BASE + 41),
    EL_TRANS_RET_CLSS_API_ORDER_ERR             =(EL_TRANS_RET_BASE + 42),
    EL_TRANS_RET_CLSS_TORN_CARDNUM_ERR          =(EL_TRANS_RET_BASE + 43),
    EL_TRANS_RET_CLSS_TORN_AID_ERR              =(EL_TRANS_RET_BASE + 44),
    EL_TRANS_RET_CLSS_TORN_AMT_ERR              =(EL_TRANS_RET_BASE + 45),
    EL_TRANS_RET_CLSS_CARD_EXPIRED_REQ_ONLINE   =(EL_TRANS_RET_BASE + 46),
    EL_TRANS_RET_CLSS_FILE_NOT_FOUND            =(EL_TRANS_RET_BASE + 47),
    EL_TRANS_RET_CLSS_TRY_AGAIN                 =(EL_TRANS_RET_BASE + 48),
    EL_TRANS_RET_CLSS_REQ_JUSTTOUCH_APP         =(EL_TRANS_RET_BASE + 49),
    EL_TRANS_RET_CLSS_DECRYPT_FAILED            =(EL_TRANS_RET_BASE + 50),
    EL_TRANS_RET_CLSS_AUTH_CONSUMER_DEVICE      =(EL_TRANS_RET_BASE + 51),
    EL_TRANS_RET_CLSS_UNNECESSARY_FAILED        =(EL_TRANS_RET_BASE + 52),
    EL_TRANS_RET_CLSS_PAYMENT_NOT_ACCEPTED      =(EL_TRANS_RET_BASE + 200),
    EL_TRANS_RET_CLSS_INSERTED_ICCARD           =(EL_TRANS_RET_BASE + 301),
    EL_TRANS_RET_CLSS_SWIPED_MAGCARD            =(EL_TRANS_RET_BASE + 302),
    //customized transaction return code
    EL_TRANS_RET_TRANS_FAILED                   =(EL_TRANS_RET_BASE + 400),
    EL_TRANS_RET_TRASN_DECLINED                 =(EL_TRANS_RET_BASE + 401),
    EL_TRANS_RET_NOT_SUPPORT                    =(EL_TRANS_RET_BASE + 402),
    EL_TRANS_RET_EXPIRED                        =(EL_TRANS_RET_BASE + 403),
    EL_TRANS_RET_LUHN_ERR                       =(EL_TRANS_RET_BASE + 404),
    EL_TRANS_RET_LUHN_NO_CARD                   =(EL_TRANS_RET_BASE + 405),
    EL_TRANS_RET_END                            =(EL_TRANS_RET_BASE + 999),
    
    
    
    EL_FILEDOWNLOAD_RET_BASE						=(7000),
    EL_FILEDOWNLOAD_ERR_INVALID_PARAM				=(EL_FILEDOWNLOAD_RET_BASE+1),
    EL_FILEDOWNLOAD_ERR_DOWNLOAD_FILE_FAIL			=(EL_FILEDOWNLOAD_RET_BASE+2),
    EL_FILEDOWNLOAD_RET_FIRMWARE_FAIL               =(EL_FILEDOWNLOAD_RET_BASE+3),
    EL_FILEDOWNLOAD_RET_FILE_OVERSIZE               =(EL_FILEDOWNLOAD_RET_BASE+4),
    EL_FILEDOWNLOAD_RET_PARSE_ERR                   =(EL_FILEDOWNLOAD_RET_BASE + 5),
    EL_FILEDOWNLOAD_RET_SIGN_ERR                    =(EL_FILEDOWNLOAD_RET_BASE + 6),
    
    EL_PARAM_RET_BASE                            = 5000,
    EL_PARAM_RET_ERR_DATA                        = (EL_PARAM_RET_BASE + 1),
    EL_PARAM_RET_INVALID_PARAM                   = (EL_PARAM_RET_BASE + 2),
    EL_PARAM_RET_PARTIAL_FAILED                  = (EL_PARAM_RET_BASE + 3),
    EL_PARAM_RET_ALL_FAILED                      = (EL_PARAM_RET_BASE + 4),
    EL_PARAM_RET_BUFFER_TOO_SMALL                = (EL_PARAM_RET_BASE + 5),
    EL_PARAM_RET_API_ORDER_ERR	                 = (EL_PARAM_RET_BASE + 6),
    EL_PARAM_RET_ENCRYPT_SENSITIVE_DATA_FAILED	 =(EL_PARAM_RET_BASE + 7),
    EL_PARAM_RET_SET_CONFIG_TLV_CMD_ERROR        = (EL_PARAM_RET_BASE + 8),
    EL_PARAM_RET_SET_EMV_TLV_CMD_ERROR           = (EL_PARAM_RET_BASE + 9),
    EL_PARAM_RET_UNSUPPORT_CARD                  = (EL_PARAM_RET_BASE + 10),
    
    
    EL_GENERAL_RET_BASE                 = 6000,
    EL_GENERAL_RET_TIMEOUT              = (EL_GENERAL_RET_BASE + 1),
    EL_GENERAL_RET_INVALID_PARAM        = (EL_GENERAL_RET_BASE + 2),
    EL_GENERAL_RET_DEVICE_NOT_EXIST     = (EL_GENERAL_RET_BASE + 3),
    EL_GENERAL_RET_DEVICE_BUSY          = (EL_GENERAL_RET_BASE + 4),
    EL_GENERAL_RET_DEVICE_NOT_OPEN      = (EL_GENERAL_RET_BASE + 5),
    EL_GENERAL_RET_USER_CANCELED        = (EL_GENERAL_RET_BASE + 6),
    EL_GENERAL_RET_CMD_NOT_SUPPORT      = (EL_GENERAL_RET_BASE + 7),
    
    
    
    EL_SDK_RET_BASE                              = 9000,
    EL_SDK_RET_PARAM_INVALID                     = (EL_SDK_RET_BASE + 1),
    EL_SDK_RET_COMM_CONNECT_ERR                  = (EL_SDK_RET_BASE + 2),
    EL_SDK_RET_COMM_DISCONNECT_ERR               = (EL_SDK_RET_BASE + 3),
    EL_SDK_RET_COMM_DISCONNECTED                 = (EL_SDK_RET_BASE + 4),
    EL_SDK_RET_COMM_SEND_ERR                     = (EL_SDK_RET_BASE + 5),
    EL_SDK_RET_COMM_RECV_ERR                     = (EL_SDK_RET_BASE + 6),
    EL_SDK_RET_FILE_NOT_EXIST                    = (EL_SDK_RET_BASE + 7),
    EL_SDK_RET_GET_DATA_FAIL                     = (EL_SDK_RET_BASE + 8),
    EL_SDK_RET_BT_NOT_ENABLED                    = (EL_SDK_RET_BASE + 9),
    EL_SDK_RET_ENC_SESSION_KEY_DEC_ERR           = (EL_SDK_RET_BASE + 10),
    
    
    EL_SDK_PROTO_RET_BASE                        = 9500,
    EL_SDK_RET_PROTO_GENERAL_ERR                 = (EL_SDK_PROTO_RET_BASE + 1),
    EL_SDK_RET_PROTO_ARG_ERR                     = (EL_SDK_PROTO_RET_BASE + 2),
    EL_SDK_RET_PROTO_PACKET_TOO_LONG             = (EL_SDK_PROTO_RET_BASE + 3),
    EL_SDK_RET_PROTO_NO_ENOUGH_DATA              = (EL_SDK_PROTO_RET_BASE + 4),
    EL_SDK_RET_PROTO_DATA_FORMAT                 = (EL_SDK_PROTO_RET_BASE + 5),
    EL_SDK_RET_PROTO_TIMEOUT                     = (EL_SDK_PROTO_RET_BASE + 6),
    
    //RKI error
    EL_RKI_RET_BASE                              = 1400,
    EL_RKI_RET_BIND_PHASE_ONE                    = (EL_RKI_RET_BASE + 1),
    EL_RKI_RET_BIND_PHASE_TWO                    = (EL_RKI_RET_BASE + 2),
    EL_RKI_RET_REBIND_PHASE_ONE                  = (EL_RKI_RET_BASE + 3),
    EL_RKI_RET_REBIND_PHASE_TWO                  = (EL_RKI_RET_BASE + 4),
    EL_RKI_RET_DOWNLOAD_PHASE_ONE                = (EL_RKI_RET_BASE + 5),
    EL_RKI_RET_DOWNLOAD_PHASE_TWO                = (EL_RKI_RET_BASE + 6),
    EL_RKI_RET_PARAM_NULL_ERR                    = (EL_RKI_RET_BASE + 7),
    EL_RKI_RET_INIT_ERR                          = (EL_RKI_RET_BASE + 8),
    EL_RKI_RET_COMM_ERR                          = (EL_RKI_RET_BASE + 9),
    EL_RKI_RET_CONSTRUCT_TLV_ERR                 = (EL_RKI_RET_BASE + 10),
    
    EL_RKI_RET_GET_DEVICE_INFO_ERR               = (EL_RKI_RET_BASE + 11),
    EL_RKI_RET_GET_DA_CERT_ERR                   = (EL_RKI_RET_BASE + 12),
    EL_RKI_RET_GET_DE_CERT_ERR                   = (EL_RKI_RET_BASE + 13),
    EL_RKI_RET_GET_RKI_INFO_ERR                  = (EL_RKI_RET_BASE + 14),
    EL_RKI_RET_PARSE_TLV_ERR                     = (EL_RKI_RET_BASE + 15),
    EL_RKI_RET_SERVICE_REJECT                    = (EL_RKI_RET_BASE + 16),
    EL_RKI_RET_SERVER_CERT_EXPIRE                = (EL_RKI_RET_BASE + 17),
    EL_RKI_RET_SERVER_CLOSE_ERR                  = (EL_RKI_RET_BASE + 18),
    EL_RKI_RET_GEN_DE_AUTH_DATA_ERR              = (EL_RKI_RET_BASE + 19),
    EL_RKI_RET_GET_AUTH_DATA_ERR                 = (EL_RKI_RET_BASE + 20),
    EL_RKI_RET_CERT_INFO_ERR                     = (EL_RKI_RET_BASE + 21),
    
    EL_RKI_RET_WRITE_AUTH_KEY_ERR                = (EL_RKI_RET_BASE + 22),
    EL_RKI_RET_DE_AUTH_TOKEN_ERR                 = (EL_RKI_RET_BASE + 23),    //EL_RKI_RET_RKI_AUTH_TOKEN_ERR
    EL_RKI_RET_WRITE_KMS_ID_ERR                  = (EL_RKI_RET_BASE + 24),
    EL_RKI_RET_VERIFY_PUK_ERR                    = (EL_RKI_RET_BASE + 25),
    EL_RKI_RET_INJECT_KEY_ERR                    = (EL_RKI_RET_BASE + 26),
    
    EL_RKI_RET_PINPAD_PROTOCOL_ERR               = (EL_RKI_RET_BASE + 27),
    EL_RKI_RET_PINPAD_INIT_ERR                   = (EL_RKI_RET_BASE + 28),
    
    EL_RKI_RET_UNBIND_WRITE_KEY_LIST_ERR         = (EL_RKI_RET_BASE + 29),
    EL_RKI_RET_UNBIND_PHASE_ONE                  = (EL_RKI_RET_BASE + 30),
    EL_RKI_RET_UNBIND_PHASE_TWO                  = (EL_RKI_RET_BASE + 31),
    
    EL_RKI_RET_INJECT_OFFLINE_KEY                = (EL_RKI_RET_BASE + 32),
    EL_RKI_RET_OFFLINE_KEY_ERR                   = (EL_RKI_RET_BASE + 33),
    EL_RKI_RET_OFFLINE_KEY_TOO_LONG              = (EL_RKI_RET_BASE + 34),
    
    EL_RKI_RET_END                               = (EL_RKI_RET_BASE + 99),
    
    EL_RKI_SERVER_RET_COMM_TIMEOUT               = 303,    //comm connect err
    EL_RKI_SERVER_RET_COMM_NET_ERR               = 305,    //comm net err
    EL_RKI_SERVER_RET_COMM_DISCONNECTED          = 307,    //comm disconnected
    EL_RKI_SERVER_RET_COMM_NOT_CONNECT           = 308,    //comm net not connect
    EL_RKI_SERVER_RET_COMM_SEND_ERR              = 309,    //comm sent err
    EL_RKI_SERVER_RET_COMM_RECV_ERR              = 310,    //comm recv err
    EL_RKI_SERVER_RET_PARAM_INVALID              = 602,    //invalid param
    EL_RKI_SERVER_RET_COMM_CONNECT_ERR           = 1201,        //comm connect err
    EL_RKI_SERVER_RET_SSL_CERT_ERR               = 1202,        //invalid cert
    
    
    // Smartlanding return code;
    EL_SML_RET_BASE                              = 1600,
    EL_SML_DB_SAVE_ERROR                         = EL_SML_RET_BASE + 1,
    EL_SML_DB_OPEN_ERROR                         = EL_SML_RET_BASE + 2,
    EL_SML_COMM_NO_CERT                          = EL_SML_RET_BASE + 3,
    EL_SML_COMM_DNS_ERROR                        = EL_SML_RET_BASE + 4,
    EL_SML_COMM_SEND_ERR                         = EL_SML_RET_BASE + 5,
    EL_SML_COMM_RECV_ERR                         = EL_SML_RET_BASE + 6,
    EL_SML_COMM_NEW_SSL_CTX_ERR                  = EL_SML_RET_BASE + 7,
    EL_SML_COMM_CREATE_SOCKET_ERR                = EL_SML_RET_BASE + 8,
    EL_SML_COMM_SET_SOCKET_OPT_ERR               = EL_SML_RET_BASE + 9,
    EL_SML_COMM_CONNECT_ERR                      = EL_SML_RET_BASE + 10,
    EL_SML_PACK_PARAM_ERR                        = EL_SML_RET_BASE + 11,
    EL_SML_PACK_TYPE_NOT_SUPPORT                 = EL_SML_RET_BASE + 12,
    EL_SML_UNPACK_FORMAT                         = EL_SML_RET_BASE + 13,
    EL_SML_UNPACK_LRC                            = EL_SML_RET_BASE + 14,
    EL_SML_DEVICE_OPEN_ERR                       = EL_SML_RET_BASE + 15,
    EL_SML_DEVICE_CONFIG_ERR                     = EL_SML_RET_BASE + 16,
    EL_SML_COMM_PARAM_ERR                        = EL_SML_RET_BASE + 17,
    EL_SML_NOT_SUPPORT_RKI_COM                   = EL_SML_RET_BASE + 18,
    EL_SML_EVN_CHECK_ERR                         = EL_SML_RET_BASE + 19,
    EL_SML_EVN_CLEAR_TASK_ERR                    = EL_SML_RET_BASE + 20,
    EL_SML_SERVER_ERR                            = EL_SML_RET_BASE + 21,
    EL_SML_DOWNLOAD_ERR                          = EL_SML_RET_BASE + 22,
    EL_SML_DOWNLOAD_MD5_ERR                      = EL_SML_RET_BASE + 23,
    EL_SML_RET_COMM_HOST_ERROR                   = EL_SML_RET_BASE + 51,
    EL_SML_RET_SYNC_ERROR                        = EL_SML_RET_BASE + 52,
    EL_SML_RET_PROCESS_ERROR                     = EL_SML_RET_BASE + 53,
    EL_SML_RET_APP_INSTALL_ERROR                 = EL_SML_RET_BASE + 54,
    EL_SML_RET_RKI_DOWNLOAD_ERROR                = EL_SML_RET_BASE + 55,
    EL_SML_RET_INVALID_DOWNLOAD_FILE             = EL_SML_RET_BASE + 56,
    EL_SML_RET_TERMINAL_NOT_REGISTER             = EL_SML_RET_BASE + 57,
    EL_SML_USER_CANCEL                           = EL_SML_RET_BASE + 99,
    
    
    //picc return code
    EL_PICC_BASE                                = 8000,
    EL_PICC_PARAM_ERROR                         = EL_PICC_BASE + 1,
    EL_PICC_RF_MODULE_CLOSE                     = EL_PICC_BASE + 2,
    EL_PICC_NO_SPECIFIC_CARD_IN_AREA            = EL_PICC_BASE + 3,
    EL_PICC_TOO_MUCH_CARD_IN_AREA               = EL_PICC_BASE + 4,
    EL_PICC_RESP_PROTOCOL_ERROR                 = EL_PICC_BASE + 5,
    EL_PICC_CARD_NOT_ACTIVATED                  = EL_PICC_BASE + 6,
    EL_PICC_MULTI_CARD_CONFLICT                 = EL_PICC_BASE + 7,
    EL_PICC_NO_RESPONSE_TIMEOUT                 = EL_PICC_BASE + 8,
    EL_PICC_PROTOCOL_ERROR                      = EL_PICC_BASE + 9,
    EL_PICC_COMM_TRANSMIT_ERROR                 = EL_PICC_BASE + 10,
    EL_PICC_M1_CARD_AUTH_FAIL                   = EL_PICC_BASE + 11,
    EL_PICC_SECTOR_NOT_CERTIFIED                = EL_PICC_BASE + 12,
    EL_PICC_DATA_FORMAT_INCORRECT               = EL_PICC_BASE + 13,
    EL_PICC_CARD_STILL_IN_AREA                  = EL_PICC_BASE + 14,
    EL_PICC_CARD_STATUS_ERROR                   = EL_PICC_BASE + 15,
    EL_PICC_INTERFACE_CHIP_ERROR                = EL_PICC_BASE + 16,
    EL_PICC_PAR_FLAG                            = EL_PICC_BASE + 17,
    EL_PICC_CRC_FLAG                            = EL_PICC_BASE + 18,
    EL_PICC_ECD_FLAG                            = EL_PICC_BASE + 19,
    EL_PICC_EMD_FLAG                            = EL_PICC_BASE + 20,
    EL_PICC_PARAMFILE_FLAG                      = EL_PICC_BASE + 21,
    EL_PICC_USER_CANCEL                         = EL_PICC_BASE + 22,
    EL_PICC_CARRIER_OBTAIN_FLAG                 = EL_PICC_BASE + 23,
    EL_PICC_CONFIG_FLAG                         = EL_PICC_BASE + 24,
    EL_PICC_RXLEN_EXCEED_FLAG                   = EL_PICC_BASE + 25,
    EL_PICC_NOT_IDLE_FLAG                       = EL_PICC_BASE + 26,
    EL_PICC__NOT_POLLING_FLAG                   = EL_PICC_BASE + 27,
    EL_PICC_NOT_WAKEUP_FLAG                     = EL_PICC_BASE + 28,
    EL_PICC_NOT_SUPPORT                         = EL_PICC_BASE + 29,
    EL_PICC_BATTERY_VOLTAGE_TOO_LOW             = EL_PICC_BASE + 30,
    EL_PICC_CHIP_ERROR                          = EL_PICC_BASE + 31,
    //msr return code
    EL_MSR_BASE                                 = 8200,
    EL_MSR_RET_FAILED                           = EL_MSR_BASE + 1,
    EL_MSR_RET_HEADE                            = EL_MSR_BASE + 2,
    EL_MSR_RET_END                              = EL_MSR_BASE + 3,
    EL_MSR_RET_LRC                              = EL_MSR_BASE + 4,
    EL_MSR_RET_PAR                              = EL_MSR_BASE + 5,
    EL_MSR_RET_NOT_SWIPED                       = EL_MSR_BASE + 6,
    EL_MSR_RET_NO_DATA                          = EL_MSR_BASE + 7,
    EL_MSR_END_RET_ZERO                         = EL_MSR_BASE + 8,
    EL_MSR_PED_RET_DECRYPT                      = EL_MSR_BASE + 9,
    EL_MSR_RET_NO_TRACK                         = EL_MSR_BASE + 10,
    //icc return code
    EL_ICC_BASE                                 = 8400,
    EL_ICC_RET_SCI_HW_NOCARD                    = EL_ICC_BASE + 1,
    EL_ICC_RET_SCI_HW_STEP                      = EL_ICC_BASE + 2,
    EL_ICC_RET_SCI_HW_PARITY                    = EL_ICC_BASE + 3,
    EL_ICC_RET_SCI_HW_TIMEOUT                   = EL_ICC_BASE + 4,
    EL_ICC_RET_SCI_TCK                          = EL_ICC_BASE + 5,
    EL_ICC_RET_SCI_ATR_TS                       = EL_ICC_BASE + 6,
    EL_ICC_RET_SCI_ATR_TA1                      = EL_ICC_BASE + 7,
    EL_ICC_RET_SCI_ATR_TD1                      = EL_ICC_BASE + 8,
    EL_ICC_RET_SCI_ATR_TA2                      = EL_ICC_BASE + 9,
    EL_ICC_RET_SCI_ATR_TB1                      = EL_ICC_BASE + 10,
    EL_ICC_RET_SCI_ATR_TB2                      = EL_ICC_BASE + 11,
    EL_ICC_RET_SCI_ATR_TC2                      = EL_ICC_BASE + 12,
    EL_ICC_RET_SCI_ATR_TD2                      = EL_ICC_BASE + 13,
    EL_ICC_RET_SCI_ATR_TA3                      = EL_ICC_BASE + 14,
    EL_ICC_RET_SCI_ATR_TB3                      = EL_ICC_BASE + 15,
    EL_ICC_RET_SCI_ATR_TC3                      = EL_ICC_BASE + 16,
    EL_ICC_RET_SCI_T_ORDER                      = EL_ICC_BASE + 17,
    EL_ICC_RET_SCI_PPS_PPSS                     = EL_ICC_BASE + 18,
    EL_ICC_RET_SCI_PPS_PPS0                     = EL_ICC_BASE + 19,
    EL_ICC_RET_SCI_PPS_PCK                      = EL_ICC_BASE + 20,
    EL_ICC_RET_SCI_T0_PARAM                     = EL_ICC_BASE + 21,
    EL_ICC_RET_SCI_T0_REPEAT                    = EL_ICC_BASE + 22,
    EL_ICC_RET_SCI_T0_PROB                      = EL_ICC_BASE + 23,
    EL_ICC_RET_SCI_T1_PARAM                     = EL_ICC_BASE + 24,
    EL_ICC_RET_SCI_T1_BWT                       = EL_ICC_BASE + 25,
    EL_ICC_RET_SCI_T1_CWT                       = EL_ICC_BASE + 26,
    EL_ICC_RET_SCI_T1_BREP                      = EL_ICC_BASE + 27,
    EL_ICC_RET_SCI_T1_LRC                       = EL_ICC_BASE + 28,
    EL_ICC_RET_SCI_T1_NAD                       = EL_ICC_BASE + 29,
    EL_ICC_RET_SCI_T1_LEN                       = EL_ICC_BASE + 30,
    EL_ICC_RET_SCI_T1_PCB                       = EL_ICC_BASE + 31,
    EL_ICC_RET_SCI_T1_SRC                       = EL_ICC_BASE + 32,
    EL_ICC_RET_SCI_T1_SRL                       = EL_ICC_BASE + 33,
    EL_ICC_RET_SCI_T1_SRA                       = EL_ICC_BASE + 34,
    EL_ICC_RET_SCI_PARAM                        = EL_ICC_BASE + 35,
    EL_ICC_RET_SCI_OTHER_ERROR                  = EL_ICC_BASE + 36,
    EL_ICC_RET_SCI_CHANNEL                      = EL_ICC_BASE + 37,
    EL_ICC_RET_SCI_DATA_LEN                     = EL_ICC_BASE + 38,
    EL_ICC_RET_SCI_T1_ABORT                     = EL_ICC_BASE + 39,
    EL_ICC_RET_SCI_T1_EDC                       = EL_ICC_BASE + 40,
    EL_ICC_RET_SCI_T1_SYNC                      = EL_ICC_BASE + 41,
    EL_ICC_RET_SCI_T1_EG                        = EL_ICC_BASE + 42,
    EL_ICC_RET_SCI_T1_BG                        = EL_ICC_BASE + 43,
    EL_ICC_RET_SCI_T1_IFSC                      = EL_ICC_BASE + 44,
    EL_ICC_RET_SCI_T1_IFSD                      = EL_ICC_BASE + 45,
    EL_ICC_RET_SCI_CHAR_GROUP_INVALID           = EL_ICC_BASE + 46,
    EL_ICC_RET_SCI_ATR_TC1                      = EL_ICC_BASE + 47,
    EL_ICC_RET_SCI_ATR_DATA_LEN                 = EL_ICC_BASE + 48,
    EL_ICC_RET_SCI_T0_TIMEOUT                   = EL_ICC_BASE + 49,
    EL_ICC_RET_SCI_T0_RESENT                    = EL_ICC_BASE + 50,
    EL_ICC_RET_SCI_T0_RECEIVE                   = EL_ICC_BASE + 51,
    EL_ICC_RET_SCI_T0_STATUS_BYTE_INVALID       = EL_ICC_BASE + 52,
    EL_ICC_RET_SCI_RE_CHAR_GROUP                = EL_ICC_BASE + 53,
    EL_ICC_RET_SCI_COMM_ERROR                   = EL_ICC_BASE + 54,
    
    
    
} PaxEasyLinkRetCode;
/*!
 @abstract PaxEasyLinkStatusCode managers the return code
 */

@interface PaxEasyLinkStatusCode : NSObject
/*!
 @abstract get PaxEasyLinkStatusCode instance
 */

+ (id)sharedInstance;

/*!
 @abstract convert the return code to the human readable string
 @param code return code
 @return the converted string
 */
- (NSString *)statusCode2String:(PaxEasyLinkRetCode)code;

@end
