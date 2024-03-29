/*********************************************************************
 *
 * $Id: yocto_api.h 15796 2014-04-15 13:36:07Z seb $
 *
 * High-level programming interface, common to all modules
 *
 * - - - - - - - - - License information: - - - - - - - - -
 *
 *  Copyright (C) 2011 and beyond by Yoctopuce Sarl, Switzerland.
 *
 *  Yoctopuce Sarl (hereafter Licensor) grants to you a perpetual
 *  non-exclusive license to use, modify, copy and integrate this
 *  file into your software for the sole purpose of interfacing 
 *  with Yoctopuce products. 
 *
 *  You may reproduce and distribute copies of this file in 
 *  source or object form, as long as the sole purpose of this
 *  code is to interface with Yoctopuce products. You must retain 
 *  this notice in the distributed source file.
 *
 *  You should refer to Yoctopuce General Terms and Conditions
 *  for additional information regarding your rights and 
 *  obligations.
 *
 *  THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 *  WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING 
 *  WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS 
 *  FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO
 *  EVENT SHALL LICENSOR BE LIABLE FOR ANY INCIDENTAL, SPECIAL,
 *  INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, 
 *  COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR 
 *  SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT 
 *  LIMITED TO ANY DEFENSE THEREOF), ANY CLAIMS FOR INDEMNITY OR
 *  CONTRIBUTION, OR OTHER SIMILAR COSTS, WHETHER ASSERTED ON THE
 *  BASIS OF CONTRACT, TORT (INCLUDING NEGLIGENCE), BREACH OF
 *  WARRANTY, OR OTHERWISE.
 *
 *********************************************************************/

#ifndef YOCTO_API_H
#define YOCTO_API_H

#include "yapi/ydef.h"
#include "yapi/yjson.h"
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stdexcept>
#include <cfloat>
#include <cmath>

#if defined(WINDOWS_API) 
#if defined(GENERATE_DLL) || defined(YOCTOPUCEDLL_EXPORTS)
#define YOCTO_CLASS_EXPORT __declspec(dllexport)
#pragma warning(disable: 4251)
#else
#define YOCTO_CLASS_EXPORT
#endif
#else
#define YOCTO_CLASS_EXPORT
#endif

using std::string;
using std::vector;
using std::queue;
using std::map;

#define YAPI_INVALID_STRING         "!INVALID!"
#define YAPI_INVALID_INT            (0x7FFFFFFF)
#define YAPI_INVALID_UINT           (-1)
#define YAPI_INVALID_LONG           (0x7FFFFFFFFFFFFFFFLL)  
#define YAPI_INVALID_DOUBLE         (-DBL_MAX)


//--- (generated code: YFunction definitions)
class YFunction; // forward declaration

typedef void (*YFunctionValueCallback)(YFunction *func, const string& functionValue);
#define Y_LOGICALNAME_INVALID           (YAPI_INVALID_STRING)
#define Y_ADVERTISEDVALUE_INVALID       (YAPI_INVALID_STRING)
//--- (end of generated code: YFunction definitions)


//--- (generated code: YModule definitions)
class YModule; // forward declaration

typedef void (*YModuleLogCallback)(YModule *module, const string& logline);
typedef void (*YModuleValueCallback)(YModule *func, const string& functionValue);
#ifndef _Y_PERSISTENTSETTINGS_ENUM
#define _Y_PERSISTENTSETTINGS_ENUM
typedef enum {
    Y_PERSISTENTSETTINGS_LOADED = 0,
    Y_PERSISTENTSETTINGS_SAVED = 1,
    Y_PERSISTENTSETTINGS_MODIFIED = 2,
    Y_PERSISTENTSETTINGS_INVALID = -1,
} Y_PERSISTENTSETTINGS_enum;
#endif

#ifndef _Y_BEACON_ENUM
#define _Y_BEACON_ENUM
typedef enum {
    Y_BEACON_OFF = 0,
    Y_BEACON_ON = 1,
    Y_BEACON_INVALID = -1,
} Y_BEACON_enum;
#endif

#ifndef _Y_USBBANDWIDTH_ENUM
#define _Y_USBBANDWIDTH_ENUM
typedef enum {
    Y_USBBANDWIDTH_SIMPLE = 0,
    Y_USBBANDWIDTH_DOUBLE = 1,
    Y_USBBANDWIDTH_INVALID = -1,
} Y_USBBANDWIDTH_enum;
#endif

#define Y_PRODUCTNAME_INVALID           (YAPI_INVALID_STRING)
#define Y_SERIALNUMBER_INVALID          (YAPI_INVALID_STRING)
#define Y_PRODUCTID_INVALID             (YAPI_INVALID_UINT)
#define Y_PRODUCTRELEASE_INVALID        (YAPI_INVALID_UINT)
#define Y_FIRMWARERELEASE_INVALID       (YAPI_INVALID_STRING)
#define Y_LUMINOSITY_INVALID            (YAPI_INVALID_UINT)
#define Y_UPTIME_INVALID                (YAPI_INVALID_LONG)
#define Y_USBCURRENT_INVALID            (YAPI_INVALID_UINT)
#define Y_REBOOTCOUNTDOWN_INVALID       (YAPI_INVALID_INT)
//--- (end of generated code: YModule definitions)

class YMeasure; // forward declaration
//--- (generated code: YSensor definitions)
class YSensor; // forward declaration

typedef void (*YSensorValueCallback)(YSensor *func, const string& functionValue);
class YMeasure; // forward declaration
typedef void (*YSensorTimedReportCallback)(YSensor *func, YMeasure measure);
#define Y_UNIT_INVALID                  (YAPI_INVALID_STRING)
#define Y_CURRENTVALUE_INVALID          (YAPI_INVALID_DOUBLE)
#define Y_LOWESTVALUE_INVALID           (YAPI_INVALID_DOUBLE)
#define Y_HIGHESTVALUE_INVALID          (YAPI_INVALID_DOUBLE)
#define Y_CURRENTRAWVALUE_INVALID       (YAPI_INVALID_DOUBLE)
#define Y_LOGFREQUENCY_INVALID          (YAPI_INVALID_STRING)
#define Y_REPORTFREQUENCY_INVALID       (YAPI_INVALID_STRING)
#define Y_CALIBRATIONPARAM_INVALID      (YAPI_INVALID_STRING)
#define Y_RESOLUTION_INVALID            (YAPI_INVALID_DOUBLE)
//--- (end of generated code: YSensor definitions)


//--- (generated code: YDataStream definitions)
//--- (end of generated code: YDataStream definitions)

//--- (generated code: YMeasure definitions)
//--- (end of generated code: YMeasure definitions)

// yInitAPI argument
const int Y_DETECT_NONE = 0;
const int Y_DETECT_USB = 1;
const int Y_DETECT_NET = 2;
const int Y_DETECT_ALL = (Y_DETECT_USB | Y_DETECT_NET);

// Forward-declaration
class YDataSet;
class YFunction;

/// prototype of the log callback
typedef void (*yLogFunction)(const string& msg);

/// prototype of the device arrival/update/removal callback
typedef void (*yDeviceUpdateCallback)(YModule *module);

/// prototype of the Hub discoverycallback
typedef void (*YHubDiscoveryCallback)(const string& serial, const string& url);



/// prototype of the value calibration handlers
typedef vector<double>  floatArr;
typedef vector<int>     intArr;
typedef double (*yCalibrationHandler)(double rawValue, int calibType, vector<int> params, vector<double> rawValues, vector<double> refValues);

typedef YAPI_DEVICE     YDEV_DESCR;
typedef YAPI_FUNCTION   YFUN_DESCR;
#define Y_FUNCTIONDESCRIPTOR_INVALID    (-1)
#define Y_HARDWAREID_INVALID            (YAPI_INVALID_STRING)
#define Y_FUNCTIONID_INVALID            (YAPI_INVALID_STRING)
#define Y_FRIENDLYNAME_INVALID          (YAPI_INVALID_STRING)

#define Y_DATA_INVALID                  (-DBL_MAX)
#define Y_DURATION_INVALID              (-1)

// 
// Class used to report exceptions within Yocto-API
// Do not instantiate directly
//
class YAPI_Exception : public std::runtime_error {
public:
    YRETCODE errorType;
    explicit YAPI_Exception(YRETCODE errType, string errMsg) : std::runtime_error(errMsg), errorType(errType) { }
};

typedef enum {
    YAPI_DEV_ARRIVAL,
    YAPI_DEV_REMOVAL,
    YAPI_DEV_CHANGE,
    YAPI_DEV_LOG,
	YAPI_HUB_DISCOVER
} yapiGlobalEventType;

typedef struct{
	yapiGlobalEventType    type;
    union{
        YModule		*module;
		struct {
			char serial[YOCTO_SERIAL_LEN];
			char url[64];
		};
    };
}yapiGlobalEvent;



typedef enum {
	YAPI_FUN_UPDATE,
	YAPI_FUN_VALUE,
	YAPI_FUN_TIMEDREPORT,
	YAPI_FUN_REFRESH
} yapiDataEventType;

typedef struct{
	yapiDataEventType    type;
	union{
		struct {
			YFunction   *fun;
			char        value[YOCTO_PUBVAL_LEN];
		};
		struct {
			YSensor    *sensor;
			double      timestamp;
			int         len;
			int			report[9];
		};
	};
}yapiDataEvent;


// internal helper function
int _ystrpos(const string& haystack, const string& needle);


// 
// YAPI Context
//
// This class provides C++-style entry points to lowlevcel functions defined to yapi.h
// Could be implemented by a singleton, we use static methods insead
//
class YOCTO_CLASS_EXPORT YAPI {
private:
    static  queue<yapiGlobalEvent>  _plug_events;
    static  queue<yapiDataEvent>    _data_events;
    static  YHubDiscoveryCallback   _HubDiscoveryCallback;
    static  u64                 _nextEnum;
    static  bool                _apiInitialized;
    static  map<int,yCalibrationHandler> _calibHandlers;
    static  void        _yapiLogFunctionFwd(const char *log, u32 loglen);
    static  void        _yapiDeviceArrivalCallbackFwd(YDEV_DESCR devdesc);
    static  void        _yapiDeviceRemovalCallbackFwd(YDEV_DESCR devdesc);
    static  void        _yapiDeviceChangeCallbackFwd(YDEV_DESCR devdesc);
    static  void        _yapiDeviceLogCallbackFwd(YDEV_DESCR devdesc, const char* line);
    static  void        _yapiFunctionTimedReportCallbackFwd(YAPI_FUNCTION fundesc, double timestamp, const u8 *bytes, u32 len);
	static  void        _yapiHubDiscoveryCallbackFwd(const char *serial, const char *url);

public:
    static  void        _yapiFunctionUpdateCallbackFwd(YFUN_DESCR fundesc, const char *value);
    static  double      _decimalToDouble(s16 val);
    static  s16         _doubleToDecimal(double val);
    static  yCalibrationHandler _getCalibrationHandler(int calibType);
    static  vector<int> _decodeWords(string s);
    
    static  int         DefaultCacheValidity;
    static  bool        ExceptionsDisabled;
    static  const string      INVALID_STRING;
    static  const int         INVALID_INT = YAPI_INVALID_INT;
    static  const int         INVALID_UINT = YAPI_INVALID_UINT;
    static  const double      INVALID_DOUBLE;
    static  const s64         INVALID_LONG = YAPI_INVALID_LONG;

    // Callback functions
    static  yLogFunction            LogFunction;
    static  yDeviceUpdateCallback   DeviceArrivalCallback;
    static  yDeviceUpdateCallback   DeviceRemovalCallback;
    static  yDeviceUpdateCallback   DeviceChangeCallback;

    static const u32 DETECT_NONE = 0;
    static const u32 DETECT_USB  = 1;
    static const u32 DETECT_NET  = 2;
    static const u32 DETECT_ALL  = (Y_DETECT_USB | Y_DETECT_NET);

//--- (generated code: YFunction return codes)
    static const int SUCCESS               = 0;       // everything worked allright
    static const int NOT_INITIALIZED       = -1;      // call yInitAPI() first !
    static const int INVALID_ARGUMENT      = -2;      // one of the arguments passed to the function is invalid
    static const int NOT_SUPPORTED         = -3;      // the operation attempted is (currently) not supported
    static const int DEVICE_NOT_FOUND      = -4;      // the requested device is not reachable
    static const int VERSION_MISMATCH      = -5;      // the device firmware is incompatible with this API version
    static const int DEVICE_BUSY           = -6;      // the device is busy with another task and cannot answer
    static const int TIMEOUT               = -7;      // the device took too long to provide an answer
    static const int IO_ERROR              = -8;      // there was an I/O problem while talking to the device
    static const int NO_MORE_DATA          = -9;      // there is no more data to read from
    static const int EXHAUSTED             = -10;     // you have run out of a limited ressource, check the documentation
    static const int DOUBLE_ACCES          = -11;     // you have two process that try to acces to the same device
    static const int UNAUTHORIZED          = -12;     // unauthorized access to password-protected device
    static const int RTC_NOT_READY         = -13;     // real-time clock has not been initialized (or time was lost)
//--- (end of generated code: YFunction return codes)


    /**
     * Returns the version identifier for the Yoctopuce library in use.
     * The version is a string in the form "Major.Minor.Build",
     * for instance "1.01.5535". For languages using an external
     * DLL (for instance C#, VisualBasic or Delphi), the character string
     * includes as well the DLL version, for instance
     * "1.01.5535 (1.01.5439)".
     * 
     * If you want to verify in your code that the library version is
     * compatible with the version that you have used during development,
     * verify that the major number is strictly equal and that the minor
     * number is greater or equal. The build number is not relevant
     * with respect to the library compatibility.
     * 
     * @return a character string describing the library version.
     */
    static string GetAPIVersion(void);


    /**
     * Initializes the Yoctopuce programming library explicitly.
     * It is not strictly needed to call yInitAPI(), as the library is
     * automatically  initialized when calling yRegisterHub() for the
     * first time.
     * 
     * When Y_DETECT_NONE is used as detection mode,
     * you must explicitly use yRegisterHub() to point the API to the
     * VirtualHub on which your devices are connected before trying to access them.
     * 
     * @param mode : an integer corresponding to the type of automatic
     *         device detection to use. Possible values are
     *         Y_DETECT_NONE, Y_DETECT_USB, Y_DETECT_NET,
     *         and Y_DETECT_ALL.
     * @param errmsg : a string passed by reference to receive any error message.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    static  YRETCODE    InitAPI(int mode, string& errmsg);

    /**
     * Frees dynamically allocated memory blocks used by the Yoctopuce library.
     * It is generally not required to call this function, unless you
     * want to free all dynamically allocated memory blocks in order to
     * track a memory leak for instance.
     * You should not call any other library function after calling
     * yFreeAPI(), or your program will crash.
     */
    static  void        FreeAPI(void);

    /**
     * Disables the use of exceptions to report runtime errors.
     * When exceptions are disabled, every function returns a specific
     * error value which depends on its type and which is documented in
     * this reference manual.
     */
    static  void        DisableExceptions(void);
    
    /**
     * Re-enables the use of exceptions for runtime error handling.
     * Be aware than when exceptions are enabled, every function that fails
     * triggers an exception. If the exception is not caught by the user code,
     * it  either fires the debugger or aborts (i.e. crash) the program.
     * On failure, throws an exception or returns a negative error code.
     */
    static  void        EnableExceptions(void); 

    /**
     * Registers a log callback function. This callback will be called each time
     * the API have something to say. Quite useful to debug the API.
     * 
     * @param logfun : a procedure taking a string parameter, or null
     *         to unregister a previously registered  callback.
     */
    static  void        RegisterLogFunction(yLogFunction logfun);

    /**
     * Register a callback function, to be called each time
     * a device is plugged. This callback will be invoked while yUpdateDeviceList
     * is running. You will have to call this function on a regular basis.
     * 
     * @param arrivalCallback : a procedure taking a YModule parameter, or null
     *         to unregister a previously registered  callback.
     */
    static  void        RegisterDeviceArrivalCallback(yDeviceUpdateCallback arrivalCallback);

    /**
     * Register a callback function, to be called each time
     * a device is unplugged. This callback will be invoked while yUpdateDeviceList
     * is running. You will have to call this function on a regular basis.
     * 
     * @param removalCallback : a procedure taking a YModule parameter, or null
     *         to unregister a previously registered  callback.
     */
    static  void        RegisterDeviceRemovalCallback(yDeviceUpdateCallback removalCallback);

    /**
     * Register a callback function, to be called each time an Network Hub send
     * an SSDP message. The callback has two string parameter, the first one
     * contain the serial number of the hub and the second contain the URL of the
     * network hub (this URL can be passed to RegisterHub). This callback will be invoked
     * while yUpdateDeviceList is running. You will have to call this function on a regular basis.
     * 
     * @param hubDiscoveryCallback : a procedure taking two string parameter, or null
     *         to unregister a previously registered  callback.
     */
    static  void        RegisterHubDiscoveryCallback(YHubDiscoveryCallback hubDiscoveryCallback);

    /**
     * Force a hub discovery, if a callback as been registered with yRegisterDeviceRemovalCallback it
     * will be called for each net work hub that will respond to the discovery.
     * 
     * @param errmsg : a string passed by reference to receive any error message.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     *         On failure, throws an exception or returns a negative error code.
     */
	static  YRETCODE    TriggerHubDiscovery(string& errmsg);


    static  void        RegisterDeviceChangeCallback(yDeviceUpdateCallback changeCallback);

    // Register a new value calibration handler for a given calibration type
    //
    static void         RegisterCalibrationHandler(int calibrationType, yCalibrationHandler calibrationHandler);
    
    // Standard value calibration handler (n-point linear error correction)
    //
    static double       LinearCalibrationHandler(double rawValue, int calibType, intArr params, floatArr rawValues, floatArr refValues);
    
    /**
     * Setup the Yoctopuce library to use modules connected on a given machine. The
     * parameter will determine how the API will work. Use the following values:
     * 
     * <b>usb</b>: When the usb keyword is used, the API will work with
     * devices connected directly to the USB bus. Some programming languages such a Javascript,
     * PHP, and Java don't provide direct access to USB hardware, so usb will
     * not work with these. In this case, use a VirtualHub or a networked YoctoHub (see below).
     * 
     * <b><i>x.x.x.x</i></b> or <b><i>hostname</i></b>: The API will use the devices connected to the
     * host with the given IP address or hostname. That host can be a regular computer
     * running a VirtualHub, or a networked YoctoHub such as YoctoHub-Ethernet or
     * YoctoHub-Wireless. If you want to use the VirtualHub running on you local
     * computer, use the IP address 127.0.0.1.
     * 
     * <b>callback</b>: that keyword make the API run in "<i>HTTP Callback</i>" mode.
     * This a special mode allowing to take control of Yoctopuce devices
     * through a NAT filter when using a VirtualHub or a networked YoctoHub. You only
     * need to configure your hub to call your server script on a regular basis.
     * This mode is currently available for PHP and Node.JS only.
     * 
     * Be aware that only one application can use direct USB access at a
     * given time on a machine. Multiple access would cause conflicts
     * while trying to access the USB modules. In particular, this means
     * that you must stop the VirtualHub software before starting
     * an application that uses direct USB access. The workaround
     * for this limitation is to setup the library to use the VirtualHub
     * rather than direct USB access.
     * 
     * If access control has been activated on the hub, virtual or not, you want to
     * reach, the URL parameter should look like:
     * 
     * http://username:password@adresse:port
     * 
     * You can call <i>RegisterHub</i> several times to connect to several machines.
     * 
     * @param url : a string containing either "usb","callback" or the
     *         root URL of the hub to monitor
     * @param errmsg : a string passed by reference to receive any error message.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    static  YRETCODE    RegisterHub(const string& url, string& errmsg);
    
    /**
     * Fault-tolerant alternative to RegisterHub(). This function has the same
     * purpose and same arguments as RegisterHub(), but does not trigger
     * an error when the selected hub is not available at the time of the function call.
     * This makes it possible to register a network hub independently of the current
     * connectivity, and to try to contact it only when a device is actively needed.
     * 
     * @param url : a string containing either "usb","callback" or the
     *         root URL of the hub to monitor
     * @param errmsg : a string passed by reference to receive any error message.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    static  YRETCODE    PreregisterHub(const string& url, string& errmsg);

    /**
     * Setup the Yoctopuce library to no more use modules connected on a previously
     * registered machine with RegisterHub.
     * 
     * @param url : a string containing either "usb" or the
     *         root URL of the hub to monitor
     */
    static  void        UnregisterHub(const string& url);

    /**
     * Triggers a (re)detection of connected Yoctopuce modules.
     * The library searches the machines or USB ports previously registered using
     * yRegisterHub(), and invokes any user-defined callback function
     * in case a change in the list of connected devices is detected.
     * 
     * This function can be called as frequently as desired to refresh the device list
     * and to make the application aware of hot-plug events.
     * 
     * @param errmsg : a string passed by reference to receive any error message.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    static  YRETCODE    UpdateDeviceList(string& errmsg);
    /**
     * Maintains the device-to-library communication channel.
     * If your program includes significant loops, you may want to include
     * a call to this function to make sure that the library takes care of
     * the information pushed by the modules on the communication channels.
     * This is not strictly necessary, but it may improve the reactivity
     * of the library for the following commands.
     * 
     * This function may signal an error in case there is a communication problem
     * while contacting a module.
     * 
     * @param errmsg : a string passed by reference to receive any error message.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    static  YRETCODE    HandleEvents(string& errmsg);
    /**
     * Pauses the execution flow for a specified duration.
     * This function implements a passive waiting loop, meaning that it does not
     * consume CPU cycles significantly. The processor is left available for
     * other threads and processes. During the pause, the library nevertheless
     * reads from time to time information from the Yoctopuce modules by
     * calling yHandleEvents(), in order to stay up-to-date.
     * 
     * This function may signal an error in case there is a communication problem
     * while contacting a module.
     * 
     * @param ms_duration : an integer corresponding to the duration of the pause,
     *         in milliseconds.
     * @param errmsg : a string passed by reference to receive any error message.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    static  YRETCODE    Sleep(unsigned ms_duration, string& errmsg);
    /**
     * Returns the current value of a monotone millisecond-based time counter.
     * This counter can be used to compute delays in relation with
     * Yoctopuce devices, which also uses the millisecond as timebase.
     * 
     * @return a long integer corresponding to the millisecond counter.
     */
    static  u64         GetTickCount(void);
    /**
     * Checks if a given string is valid as logical name for a module or a function.
     * A valid logical name has a maximum of 19 characters, all among
     * A..Z, a..z, 0..9, _, and -.
     * If you try to configure a logical name with an incorrect string,
     * the invalid characters are ignored.
     * 
     * @param name : a string containing the name to check.
     * 
     * @return true if the name is valid, false otherwise.
     */
    static  bool        CheckLogicalName(const string& name);
};

    
// Wrappers to yapi low-level API
class YapiWrapper {
public:
    static  u16         getAPIVersion(string& version, string& date);
    static  YDEV_DESCR  getDevice(const string& device_str, string& errmsg);
    static  int         getAllDevices(vector<YDEV_DESCR>& buffer, string& errmsg);
    static  YRETCODE    getDeviceInfo(YDEV_DESCR devdesc, yDeviceSt& infos, string& errmsg);
    static  YFUN_DESCR  getFunction(const string& class_str, const string& function_str, string& errmsg);
    static  int         getFunctionsByClass(const string& class_str, YFUN_DESCR prevfundesc, vector<YFUN_DESCR>& buffer, int maxsize, string& errmsg);
    static  int         getFunctionsByDevice(YDEV_DESCR devdesc, YFUN_DESCR prevfundesc, vector<YFUN_DESCR>& buffer, int maxsize, string& errmsg);
    static  YDEV_DESCR  getDeviceByFunction(YFUN_DESCR fundesc, string& errmsg);
    static  YRETCODE    getFunctionInfo(YFUN_DESCR fundesc, YDEV_DESCR& devdescr, string& serial, string& funcId, string& funcName, string& funcVal, string& errmsg);
    // pure yapi mapper
    static  YRETCODE    updateDeviceList(bool forceupdate, string& errmsg);
    static  YRETCODE    handleEvents(string& errmsg);
    static  string      ysprintf(const char *fmt, ...);
};

//--- (generated code: YDataStream declaration)
/**
 * YDataStream Class: Unformatted data sequence
 * 
 * YDataStream objects represent bare recorded measure sequences,
 * exactly as found within the data logger present on Yoctopuce
 * sensors.
 * 
 * In most cases, it is not necessary to use YDataStream objects
 * directly, as the YDataSet objects (returned by the
 * get_recordedData() method from sensors and the
 * get_dataSets() method from the data logger) provide
 * a more convenient interface.
 */
class YOCTO_CLASS_EXPORT YDataStream {
//--- (end of generated code: YDataStream declaration)
protected:
    //--- (generated code: YDataStream attributes)
    // Attributes (function value cache)
    YFunction*      _parent;
    int             _runNo;
    s64             _utcStamp;
    int             _nCols;
    int             _nRows;
    int             _duration;
    vector<string>  _columnNames;
    string          _functionId;
    bool            _isClosed;
    bool            _isAvg;
    bool            _isScal;
    int             _decimals;
    double          _offset;
    double          _scale;
    int             _samplesPerHour;
    double          _minVal;
    double          _avgVal;
    double          _maxVal;
    double          _decexp;
    int             _caltyp;
    vector<int>     _calpar;
    vector<double>  _calraw;
    vector<double>  _calref;
    vector< vector<double> > _values;
    //--- (end of generated code: YDataStream attributes)
 
    yCalibrationHandler _calhdl;
    
public:    
    YDataStream(YFunction *parent): _parent(parent) {};
    YDataStream(YFunction *parent, YDataSet &dataset, const vector<int>& encoded);
    
    static const double DATA_INVALID;
    static const int    DURATION_INVALID = -1;
    
    //--- (generated code: YDataStream accessors declaration)


    virtual int         _initFromDataSet(YDataSet* dataset,vector<int> encoded);

    virtual int         parse(string sdata);

    virtual string      get_url(void);

    virtual int         loadStream(void);

    virtual double      _decodeVal(int w);

    virtual double      _decodeAvg(int dw,int count);

    virtual bool        isClosed(void);

    /**
     * Returns the run index of the data stream. A run can be made of
     * multiple datastreams, for different time intervals.
     * 
     * @return an unsigned number corresponding to the run index.
     */
    virtual int         get_runIndex(void);

    /**
     * Returns the relative start time of the data stream, measured in seconds.
     * For recent firmwares, the value is relative to the present time,
     * which means the value is always negative.
     * If the device uses a firmware older than version 13000, value is
     * relative to the start of the time the device was powered on, and
     * is always positive.
     * If you need an absolute UTC timestamp, use get_startTimeUTC().
     * 
     * @return an unsigned number corresponding to the number of seconds
     *         between the start of the run and the beginning of this data
     *         stream.
     */
    virtual int         get_startTime(void);

    /**
     * Returns the start time of the data stream, relative to the Jan 1, 1970.
     * If the UTC time was not set in the datalogger at the time of the recording
     * of this data stream, this method returns 0.
     * 
     * @return an unsigned number corresponding to the number of seconds
     *         between the Jan 1, 1970 and the beginning of this data
     *         stream (i.e. Unix time representation of the absolute time).
     */
    virtual s64         get_startTimeUTC(void);

    /**
     * Returns the number of milliseconds between two consecutive
     * rows of this data stream. By default, the data logger records one row
     * per second, but the recording frequency can be changed for
     * each device function
     * 
     * @return an unsigned number corresponding to a number of milliseconds.
     */
    virtual int         get_dataSamplesIntervalMs(void);

    virtual double      get_dataSamplesInterval(void);

    /**
     * Returns the number of data rows present in this stream.
     * 
     * If the device uses a firmware older than version 13000,
     * this method fetches the whole data stream from the device
     * if not yet done, which can cause a little delay.
     * 
     * @return an unsigned number corresponding to the number of rows.
     * 
     * On failure, throws an exception or returns zero.
     */
    virtual int         get_rowCount(void);

    /**
     * Returns the number of data columns present in this stream.
     * The meaning of the values present in each column can be obtained
     * using the method get_columnNames().
     * 
     * If the device uses a firmware older than version 13000,
     * this method fetches the whole data stream from the device
     * if not yet done, which can cause a little delay.
     * 
     * @return an unsigned number corresponding to the number of columns.
     * 
     * On failure, throws an exception or returns zero.
     */
    virtual int         get_columnCount(void);

    /**
     * Returns the title (or meaning) of each data column present in this stream.
     * In most case, the title of the data column is the hardware identifier
     * of the sensor that produced the data. For streams recorded at a lower
     * recording rate, the dataLogger stores the min, average and max value
     * during each measure interval into three columns with suffixes _min,
     * _avg and _max respectively.
     * 
     * If the device uses a firmware older than version 13000,
     * this method fetches the whole data stream from the device
     * if not yet done, which can cause a little delay.
     * 
     * @return a list containing as many strings as there are columns in the
     *         data stream.
     * 
     * On failure, throws an exception or returns an empty array.
     */
    virtual vector<string> get_columnNames(void);

    /**
     * Returns the smallest measure observed within this stream.
     * If the device uses a firmware older than version 13000,
     * this method will always return Y_DATA_INVALID.
     * 
     * @return a floating-point number corresponding to the smallest value,
     *         or Y_DATA_INVALID if the stream is not yet complete (still recording).
     * 
     * On failure, throws an exception or returns Y_DATA_INVALID.
     */
    virtual double      get_minValue(void);

    /**
     * Returns the average of all measures observed within this stream.
     * If the device uses a firmware older than version 13000,
     * this method will always return Y_DATA_INVALID.
     * 
     * @return a floating-point number corresponding to the average value,
     *         or Y_DATA_INVALID if the stream is not yet complete (still recording).
     * 
     * On failure, throws an exception or returns Y_DATA_INVALID.
     */
    virtual double      get_averageValue(void);

    /**
     * Returns the largest measure observed within this stream.
     * If the device uses a firmware older than version 13000,
     * this method will always return Y_DATA_INVALID.
     * 
     * @return a floating-point number corresponding to the largest value,
     *         or Y_DATA_INVALID if the stream is not yet complete (still recording).
     * 
     * On failure, throws an exception or returns Y_DATA_INVALID.
     */
    virtual double      get_maxValue(void);

    /**
     * Returns the approximate duration of this stream, in seconds.
     * 
     * @return the number of seconds covered by this stream.
     * 
     * On failure, throws an exception or returns Y_DURATION_INVALID.
     */
    virtual int         get_duration(void);

    /**
     * Returns the whole data set contained in the stream, as a bidimensional
     * table of numbers.
     * The meaning of the values present in each column can be obtained
     * using the method get_columnNames().
     * 
     * This method fetches the whole data stream from the device,
     * if not yet done.
     * 
     * @return a list containing as many elements as there are rows in the
     *         data stream. Each row itself is a list of floating-point
     *         numbers.
     * 
     * On failure, throws an exception or returns an empty array.
     */
    virtual vector< vector<double> > get_dataRows(void);

    /**
     * Returns a single measure from the data stream, specified by its
     * row and column index.
     * The meaning of the values present in each column can be obtained
     * using the method get_columnNames().
     * 
     * This method fetches the whole data stream from the device,
     * if not yet done.
     * 
     * @param row : row index
     * @param col : column index
     * 
     * @return a floating-point number
     * 
     * On failure, throws an exception or returns Y_DATA_INVALID.
     */
    virtual double      get_data(int row,int col);

    //--- (end of generated code: YDataStream accessors declaration)
};

//--- (generated code: YMeasure declaration)
/**
 * YMeasure Class: Measured value
 * 
 * YMeasure objects are used within the API to represent
 * a value measured at a specified time. These objects are
 * used in particular in conjunction with the YDataSet class.
 */
class YOCTO_CLASS_EXPORT YMeasure {
//--- (end of generated code: YMeasure declaration)
protected:
    //--- (generated code: YMeasure attributes)
    // Attributes (function value cache)
    double          _start;
    double          _end;
    double          _minVal;
    double          _avgVal;
    double          _maxVal;
    //--- (end of generated code: YMeasure attributes)
 

    time_t              _startTime_t;
    time_t              _stopTime_t;
public:
    YMeasure(double start, double end, double minVal, double avgVal, double maxVal):
        _start(start), _end(end), _minVal(minVal), _avgVal(avgVal), _maxVal(maxVal),_startTime_t((time_t)(start+0.5)),_stopTime_t((time_t)(end+0.5)) {};

    YMeasure(): _start(0), _end(0), _minVal(0), _avgVal(0), _maxVal(0),_startTime_t(0),_stopTime_t(0) {};

    time_t*        get_startTimeUTC_asTime_t(time_t *time);
    time_t*        get_endTimeUTC_asTime_t(time_t *time);
    
    //--- (generated code: YMeasure accessors declaration)


    /**
     * Returns the start time of the measure, relative to the Jan 1, 1970 UTC
     * (Unix timestamp). When the recording rate is higher then 1 sample
     * per second, the timestamp may have a fractional part.
     * 
     * @return an floating point number corresponding to the number of seconds
     *         between the Jan 1, 1970 UTC and the beginning of this measure.
     */
    virtual double      get_startTimeUTC(void);

    /**
     * Returns the end time of the measure, relative to the Jan 1, 1970 UTC
     * (Unix timestamp). When the recording rate is higher than 1 sample
     * per second, the timestamp may have a fractional part.
     * 
     * @return an floating point number corresponding to the number of seconds
     *         between the Jan 1, 1970 UTC and the end of this measure.
     */
    virtual double      get_endTimeUTC(void);

    /**
     * Returns the smallest value observed during the time interval
     * covered by this measure.
     * 
     * @return a floating-point number corresponding to the smallest value observed.
     */
    virtual double      get_minValue(void);

    /**
     * Returns the average value observed during the time interval
     * covered by this measure.
     * 
     * @return a floating-point number corresponding to the average value observed.
     */
    virtual double      get_averageValue(void);

    /**
     * Returns the largest value observed during the time interval
     * covered by this measure.
     * 
     * @return a floating-point number corresponding to the largest value observed.
     */
    virtual double      get_maxValue(void);

    //--- (end of generated code: YMeasure accessors declaration)
};



//--- (generated code: YDataSet declaration)
/**
 * YDataSet Class: Recorded data sequence
 * 
 * YDataSet objects make it possible to retrieve a set of recorded measures
 * for a given sensor and a specified time interval. They can be used
 * to load data points with a progress report. When the YDataSet object is
 * instanciated by the get_recordedData()  function, no data is
 * yet loaded from the module. It is only when the loadMore()
 * method is called over and over than data will be effectively loaded
 * from the dataLogger.
 * 
 * A preview of available measures is available using the function
 * get_preview() as soon as loadMore() has been called
 * once. Measures themselves are available using function get_measures()
 * when loaded by subsequent calls to loadMore().
 * 
 * This class can only be used on devices that use a recent firmware,
 * as YDataSet objects are not supported by firmwares older than version 13000.
 */
class YOCTO_CLASS_EXPORT YDataSet {
//--- (end of generated code: YDataSet declaration)
protected:
    //--- (generated code: YDataSet attributes)
    // Attributes (function value cache)
    YFunction*      _parent;
    string          _hardwareId;
    string          _functionId;
    string          _unit;
    s64             _startTime;
    s64             _endTime;
    int             _progress;
    vector<int>     _calib;
    vector<YDataStream*> _streams;
    YMeasure        _summary;
    vector<YMeasure> _preview;
    vector<YMeasure> _measures;
    //--- (end of generated code: YDataSet attributes)
 
    int _parse(const string& json);

public:
    YDataSet(YFunction *parent, const string& functionId, const string& unit, s64 startTime, s64 endTime);
    YDataSet(YFunction *parent, const string& json);

    //--- (generated code: YDataSet accessors declaration)


    virtual vector<int> get_calibration(void);

    virtual int         processMore(int progress,string data);

    virtual vector<YDataStream*> get_privateDataStreams(void);

    /**
     * Returns the unique hardware identifier of the function who performed the measures,
     * in the form SERIAL.FUNCTIONID. The unique hardware identifier is composed of the
     * device serial number and of the hardware identifier of the function
     * (for example THRMCPL1-123456.temperature1)
     * 
     * @return a string that uniquely identifies the function (ex: THRMCPL1-123456.temperature1)
     * 
     * On failure, throws an exception or returns  Y_HARDWAREID_INVALID.
     */
    virtual string      get_hardwareId(void);

    /**
     * Returns the hardware identifier of the function that performed the measure,
     * without reference to the module. For example temperature1.
     * 
     * @return a string that identifies the function (ex: temperature1)
     */
    virtual string      get_functionId(void);

    /**
     * Returns the measuring unit for the measured value.
     * 
     * @return a string that represents a physical unit.
     * 
     * On failure, throws an exception or returns  Y_UNIT_INVALID.
     */
    virtual string      get_unit(void);

    /**
     * Returns the start time of the dataset, relative to the Jan 1, 1970.
     * When the YDataSet is created, the start time is the value passed
     * in parameter to the get_dataSet() function. After the
     * very first call to loadMore(), the start time is updated
     * to reflect the timestamp of the first measure actually found in the
     * dataLogger within the specified range.
     * 
     * @return an unsigned number corresponding to the number of seconds
     *         between the Jan 1, 1970 and the beginning of this data
     *         set (i.e. Unix time representation of the absolute time).
     */
    virtual s64         get_startTimeUTC(void);

    /**
     * Returns the end time of the dataset, relative to the Jan 1, 1970.
     * When the YDataSet is created, the end time is the value passed
     * in parameter to the get_dataSet() function. After the
     * very first call to loadMore(), the end time is updated
     * to reflect the timestamp of the last measure actually found in the
     * dataLogger within the specified range.
     * 
     * @return an unsigned number corresponding to the number of seconds
     *         between the Jan 1, 1970 and the end of this data
     *         set (i.e. Unix time representation of the absolute time).
     */
    virtual s64         get_endTimeUTC(void);

    /**
     * Returns the progress of the downloads of the measures from the data logger,
     * on a scale from 0 to 100. When the object is instanciated by get_dataSet,
     * the progress is zero. Each time loadMore() is invoked, the progress
     * is updated, to reach the value 100 only once all measures have been loaded.
     * 
     * @return an integer in the range 0 to 100 (percentage of completion).
     */
    virtual int         get_progress(void);

    /**
     * Loads the the next block of measures from the dataLogger, and updates
     * the progress indicator.
     * 
     * @return an integer in the range 0 to 100 (percentage of completion),
     *         or a negative error code in case of failure.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    virtual int         loadMore(void);

    /**
     * Returns an YMeasure object which summarizes the whole
     * DataSet. In includes the following information:
     * - the start of a time interval
     * - the end of a time interval
     * - the minimal value observed during the time interval
     * - the average value observed during the time interval
     * - the maximal value observed during the time interval
     * 
     * This summary is available as soon as loadMore() has
     * been called for the first time.
     * 
     * @return an YMeasure object
     */
    virtual YMeasure    get_summary(void);

    /**
     * Returns a condensed version of the measures that can
     * retrieved in this YDataSet, as a list of YMeasure
     * objects. Each item includes:
     * - the start of a time interval
     * - the end of a time interval
     * - the minimal value observed during the time interval
     * - the average value observed during the time interval
     * - the maximal value observed during the time interval
     * 
     * This preview is available as soon as loadMore() has
     * been called for the first time.
     * 
     * @return a table of records, where each record depicts the
     *         measured values during a time interval
     * 
     * On failure, throws an exception or returns an empty array.
     */
    virtual vector<YMeasure> get_preview(void);

    /**
     * Returns all measured values currently available for this DataSet,
     * as a list of YMeasure objects. Each item includes:
     * - the start of the measure time interval
     * - the end of the measure time interval
     * - the minimal value observed during the time interval
     * - the average value observed during the time interval
     * - the maximal value observed during the time interval
     * 
     * Before calling this method, you should call loadMore()
     * to load data from the device. You may have to call loadMore()
     * several time until all rows are loaded, but you can start
     * looking at available data rows before the load is complete.
     * 
     * The oldest measures are always loaded first, and the most
     * recent measures will be loaded last. As a result, timestamps
     * are normally sorted in ascending order within the measure table,
     * unless there was an unexpected adjustment of the datalogger UTC
     * clock.
     * 
     * @return a table of records, where each record depicts the
     *         measured value for a given time interval
     * 
     * On failure, throws an exception or returns an empty array.
     */
    virtual vector<YMeasure> get_measures(void);

    //--- (end of generated code: YDataSet accessors declaration)
};

// 
// YDevice Class (used internally)
//
// This class is used to cache device-level information
//
// In order to regroup multiple function queries on the same physical device,
// this class implements a device-wide API string cache (agnostic of API content).
// This is in addition to the function-specific cache implemented in YFunction.
//

class YDevice;

typedef void (*HTTPRequestCallback)(YDevice *device,void *context,YRETCODE returnval, const string& result,string& errmsg);

class YDevice
{
private:    
    // Static device-based JSON string cache
    static vector<YDevice*> _devCache;
    
    // Device cache entries
    YDEV_DESCR          _devdescr;    
    u64                 _cacheStamp; // used only by requestAPI method
    string              _cacheJson;  // used only ba requestAPI method
    vector<YFUN_DESCR>  _functions;
    char                _rootdevice[YOCTO_SERIAL_LEN];
    char                *_subpath;

  
    // Constructor is private, use getDevice factory method
    YDevice(YDEV_DESCR devdesc);
    ~YDevice();
    YRETCODE   HTTPRequestPrepare(const string& request, string& fullrequest, char *errbuff);

public:
    static void ClearCache();
    static YDevice *getDevice(YDEV_DESCR devdescr);
    YRETCODE    HTTPRequestAsync(const string& request, HTTPRequestCallback callback, void *context, string& errmsg);
    YRETCODE    HTTPRequest(const string& request, string& buffer, string& errmsg);
    YRETCODE    requestAPI(string& apires, string& errmsg);
    YRETCODE    getFunctions(vector<YFUN_DESCR> **functions, string& errmsg);

};

//--- (generated code: YFunction declaration)
/**
 * YFunction Class: Common function interface
 * 
 * This is the parent class for all public objects representing device functions documented in
 * the high-level programming API. This abstract class does all the real job, but without
 * knowledge of the specific function attributes.
 * 
 * Instantiating a child class of YFunction does not cause any communication.
 * The instance simply keeps track of its function identifier, and will dynamically bind
 * to a matching device at the time it is really being used to read or set an attribute.
 * In order to allow true hot-plug replacement of one device by another, the binding stay
 * dynamic through the life of the object.
 * 
 * The YFunction class implements a generic high-level cache for the attribute values of
 * the specified function, pre-parsed from the REST API string.
 */
class YOCTO_CLASS_EXPORT YFunction {
//--- (end of generated code: YFunction declaration)
protected:
    // Protected attributes
    string      _className;
    string      _func;
    YRETCODE    _lastErrorType;
    string      _lastErrorMsg;
    YFUN_DESCR  _fundescr;
    std::map<string,YDataStream*> _dataStreams;
    void*                   _userData;
    //--- (generated code: YFunction attributes)
    // Attributes (function value cache)
    string          _logicalName;
    string          _advertisedValue;
    YFunctionValueCallback _valueCallbackFunction;
    u64             _cacheExpiration;
    string          _serial;
    string          _funId;
    string          _hwId;

    friend YFunction *yFindFunction(const string& func);
    friend YFunction *yFirstFunction(void);

    // Function-specific method for parsing of JSON output and caching result
    virtual int     _parseAttr(yJsonStateMachine& j);

    // Constructor is protected, use yFindFunction factory function to instantiate
    YFunction(const string& func);
    //--- (end of generated code: YFunction attributes)
    static  std::map<string,YFunction*> _cache;
    

    // Method used to retrieve our unique function descriptor (may trigger a hub scan)
    YRETCODE    _getDescriptor(YFUN_DESCR& fundescr, string& errMsg);
    
    // Method used to retrieve our device object (may trigger a hub scan)
    YRETCODE    _getDevice(YDevice*& dev, string& errMsg);

    // Method used to find the next instance of our function
    YRETCODE    _nextFunction(string &hwId);
    
    int         _parse(yJsonStateMachine& j);

    YRETCODE    _buildSetRequest( const string& changeattr, const string  *changeval, string& request, string& errmsg);
    
    // Method used to change attributes
    YRETCODE    _setAttr(string attrname, string newvalue);
    
    static void _UpdateValueCallbackList(YFunction* func, bool add);
    static void _UpdateTimedReportCallbackList(YFunction* func, bool add);

    // function cache methods
    static YFunction*  _FindFromCache(const string& classname, const string& func);
    static void        _AddToCache(const string& classname, const string& func, YFunction *obj);
   
public:
    virtual ~YFunction();
    
    // clear cache of all YFunction object (use only on YAPI::FreeAPI)
    static void _ClearCache(void);

    // Method used to throw exceptions or save error type/message
    void        _throw(YRETCODE errType, string errMsg);
    
    // Method used to send http request to the device (not the function)
    string      _request(const string& request);
    string      _download(const string& url);
    
    // Method used to upload a file to the device
    YRETCODE    _upload(const string& path, const string& content);

    // Method used to parse a string in JSON data (low-level)
    string      _json_get_key(const string& json, const string& data);
    string      _json_get_string(const string& json);
    vector<string> _json_get_array(const string& json);
    string      _parseString(yJsonStateMachine& j);
    int         _parseEx(yJsonStateMachine& j);



    // Method used to cache DataStream objects (new DataLogger)
    YDataStream *_findDataStream(YDataSet& dataset, const string& def);
    
    static const YFUN_DESCR FUNCTIONDESCRIPTOR_INVALID = Y_FUNCTIONDESCRIPTOR_INVALID;
    static const string     HARDWAREID_INVALID;
    static const string     FUNCTIONID_INVALID;
    static const string     FRIENDLYNAME_INVALID;
    


    //--- (generated code: YFunction accessors declaration)

    static const string LOGICALNAME_INVALID;
    static const string ADVERTISEDVALUE_INVALID;

    /**
     * Returns the logical name of the function.
     * 
     * @return a string corresponding to the logical name of the function
     * 
     * On failure, throws an exception or returns Y_LOGICALNAME_INVALID.
     */
    string              get_logicalName(void);

    inline string       logicalName(void)
    { return this->get_logicalName(); }

    /**
     * Changes the logical name of the function. You can use yCheckLogicalName()
     * prior to this call to make sure that your parameter is valid.
     * Remember to call the saveToFlash() method of the module if the
     * modification must be kept.
     * 
     * @param newval : a string corresponding to the logical name of the function
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_logicalName(const string& newval);
    inline int      setLogicalName(const string& newval)
    { return this->set_logicalName(newval); }

    /**
     * Returns the current value of the function (no more than 6 characters).
     * 
     * @return a string corresponding to the current value of the function (no more than 6 characters)
     * 
     * On failure, throws an exception or returns Y_ADVERTISEDVALUE_INVALID.
     */
    string              get_advertisedValue(void);

    inline string       advertisedValue(void)
    { return this->get_advertisedValue(); }

    /**
     * Retrieves a function for a given identifier.
     * The identifier can be specified using several formats:
     * <ul>
     * <li>FunctionLogicalName</li>
     * <li>ModuleSerialNumber.FunctionIdentifier</li>
     * <li>ModuleSerialNumber.FunctionLogicalName</li>
     * <li>ModuleLogicalName.FunctionIdentifier</li>
     * <li>ModuleLogicalName.FunctionLogicalName</li>
     * </ul>
     * 
     * This function does not require that the function is online at the time
     * it is invoked. The returned object is nevertheless valid.
     * Use the method YFunction.isOnline() to test if the function is
     * indeed online at a given time. In case of ambiguity when looking for
     * a function by logical name, no error is notified: the first instance
     * found is returned. The search is performed first by hardware name,
     * then by logical name.
     * 
     * @param func : a string that uniquely characterizes the function
     * 
     * @return a YFunction object allowing you to drive the function.
     */
    static YFunction*   FindFunction(string func);

    /**
     * Registers the callback function that is invoked on every change of advertised value.
     * The callback is invoked only during the execution of ySleep or yHandleEvents.
     * This provides control over the time when the callback is triggered. For good responsiveness, remember to call
     * one of these two functions periodically. To unregister a callback, pass a null pointer as argument.
     * 
     * @param callback : the callback function to call, or a null pointer. The callback function should take two
     *         arguments: the function object of which the value has changed, and the character string describing
     *         the new advertised value.
     * @noreturn
     */
    virtual int         registerValueCallback(YFunctionValueCallback callback);

    virtual int         _invokeValueCallback(string value);

    virtual int         _parserHelper(void);


    inline static YFunction* Find(string func)
    { return YFunction::FindFunction(func); }

    /**
     * comment from .yc definition
     */
           YFunction       *nextFunction(void);
    inline YFunction       *next(void)
    { return this->nextFunction();}

    /**
     * comment from .yc definition
     */
           static YFunction* FirstFunction(void);
    inline static YFunction* First(void)
    { return YFunction::FirstFunction();}
    //--- (end of generated code: YFunction accessors declaration)



    /**
     * Returns a short text that describes unambiguously the instance of the function in the form
     * TYPE(NAME)=SERIAL&#46;FUNCTIONID.
     * More precisely,
     * TYPE       is the type of the function,
     * NAME       it the name used for the first access to the function,
     * SERIAL     is the serial number of the module if the module is connected or "unresolved", and
     * FUNCTIONID is  the hardware identifier of the function if the module is connected.
     * For example, this method returns Relay(MyCustomName.relay1)=RELAYLO1-123456.relay1 if the
     * module is already connected or Relay(BadCustomeName.relay1)=unresolved if the module has
     * not yet been connected. This method does not trigger any USB or TCP transaction and can therefore be used in
     * a debugger.
     * 
     * @return a string that describes the function
     *         (ex: Relay(MyCustomName.relay1)=RELAYLO1-123456.relay1)
     */
    string      describe(void);

    /**
     * Returns a global identifier of the function in the format MODULE_NAME&#46;FUNCTION_NAME.
     * The returned string uses the logical names of the module and of the function if they are defined,
     * otherwise the serial number of the module and the hardware identifier of the function
     * (for exemple: MyCustomName.relay1)
     * 
     * @return a string that uniquely identifies the function using logical names
     *         (ex: MyCustomName.relay1)
     * 
     * On failure, throws an exception or returns  Y_FRIENDLYNAME_INVALID.
     */
     virtual string      get_friendlyName(void);

    /**
     * Returns the unique hardware identifier of the function in the form SERIAL.FUNCTIONID.
     * The unique hardware identifier is composed of the device serial
     * number and of the hardware identifier of the function (for example RELAYLO1-123456.relay1).
     * 
     * @return a string that uniquely identifies the function (ex: RELAYLO1-123456.relay1)
     * 
     * On failure, throws an exception or returns  Y_HARDWAREID_INVALID.
     */
    string      get_hardwareId(void);

    /**
     * Returns the hardware identifier of the function, without reference to the module. For example
     * relay1
     * 
     * @return a string that identifies the function (ex: relay1)
     * 
     * On failure, throws an exception or returns  Y_FUNCTIONID_INVALID.
     */
    string      get_functionId(void);

    
    /**
     * Returns the numerical error code of the latest error with the function.
     * This method is mostly useful when using the Yoctopuce library with
     * exceptions disabled.
     * 
     * @return a number corresponding to the code of the latest error that occured while
     *         using the function object
     */
           YRETCODE    get_errorType(void);
    inline YRETCODE    errorType(void)
    {return this->get_errorType();}
    inline YRETCODE    errType(void)
    {return this->get_errorType();}
    
    /**
     * Returns the error message of the latest error with the function.
     * This method is mostly useful when using the Yoctopuce library with
     * exceptions disabled.
     * 
     * @return a string corresponding to the latest error message that occured while
     *         using the function object
     */
           string      get_errorMessage(void);
    inline string      errorMessage(void)
    {return this->get_errorMessage();}
    inline string      errMessage(void)
    {return this->get_errorMessage();}
    
    /**
     * Checks if the function is currently reachable, without raising any error.
     * If there is a cached value for the function in cache, that has not yet
     * expired, the device is considered reachable.
     * No exception is raised if there is an error while trying to contact the
     * device hosting the function.
     * 
     * @return true if the function can be reached, and false otherwise
     */
    bool        isOnline(void);

    /**
     * Preloads the function cache with a specified validity duration.
     * By default, whenever accessing a device, all function attributes
     * are kept in cache for the standard duration (5 ms). This method can be
     * used to temporarily mark the cache as valid for a longer period, in order
     * to reduce network trafic for instance.
     * 
     * @param msValidity : an integer corresponding to the validity attributed to the
     *         loaded function parameters, in milliseconds
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    YRETCODE    load(int msValidity);

    /**
     * Gets the YModule object for the device on which the function is located.
     * If the function cannot be located on any module, the returned instance of
     * YModule is not shown as on-line.
     * 
     * @return an instance of YModule
     */
           YModule     *get_module(void);
    inline YModule     *module(void)
    {return this->get_module();}

    /**
     * Returns a unique identifier of type YFUN_DESCR corresponding to the function.
     * This identifier can be used to test if two instances of YFunction reference the same
     * physical function on the same physical device.
     * 
     * @return an identifier of type YFUN_DESCR.
     * 
     * If the function has never been contacted, the returned value is Y_FUNCTIONDESCRIPTOR_INVALID.
     */
           YFUN_DESCR     get_functionDescriptor(void);
    inline YFUN_DESCR     functionDescriptor(void)
    {return this->get_functionDescriptor();}

    /**
     * Returns the value of the userData attribute, as previously stored using method
     * set_userData.
     * This attribute is never touched directly by the API, and is at disposal of the caller to
     * store a context.
     * 
     * @return the object stored previously by the caller.
     */
           void        *get_userData(void);
    inline void        *userData(void)
    {return this->get_userData();}

    /**
     * Stores a user context provided as argument in the userData attribute of the function.
     * This attribute is never touched by the API, and is at disposal of the caller to store a context.
     * 
     * @param data : any kind of object to be stored
     * @noreturn
     */
           void        set_userData(void* data);
    inline void        setUserData(void* data)
    { this->set_userData(data);}
    
};


typedef void(*YModuleLogCallback)(YModule *module, const string& log);

//--- (generated code: YModule declaration)
/**
 * YModule Class: Module control interface
 * 
 * This interface is identical for all Yoctopuce USB modules.
 * It can be used to control the module global parameters, and
 * to enumerate the functions provided by each module.
 */
class YOCTO_CLASS_EXPORT YModule: public YFunction {
//--- (end of generated code: YModule declaration)
protected:
    //--- (generated code: YModule attributes)
    // Attributes (function value cache)
    string          _productName;
    string          _serialNumber;
    int             _productId;
    int             _productRelease;
    string          _firmwareRelease;
    Y_PERSISTENTSETTINGS_enum _persistentSettings;
    int             _luminosity;
    Y_BEACON_enum   _beacon;
    s64             _upTime;
    int             _usbCurrent;
    int             _rebootCountdown;
    Y_USBBANDWIDTH_enum _usbBandwidth;
    YModuleValueCallback _valueCallbackModule;
    YModuleLogCallback _logCallback;

    friend YModule *yFindModule(const string& func);
    friend YModule *yFirstModule(void);

    // Function-specific method for parsing of JSON output and caching result
    virtual int     _parseAttr(yJsonStateMachine& j);

    // Constructor is protected, use yFindModule factory function to instantiate
    YModule(const string& func);
    //--- (end of generated code: YModule attributes)
    //--- (generated code: Module initialization)
    //--- (end of generated code: Module initialization)

    // Method used to retrieve details of the nth function of our device
    YRETCODE        _getFunction(int idx, string& serial, string& funcId, string& funcName, string& funcVal, string& errMsg);
    
public:
    ~YModule();
    
    /**
     * Returns a global identifier of the function in the format MODULE_NAME&#46;FUNCTION_NAME.
     * The returned string uses the logical names of the module and of the function if they are defined,
     * otherwise the serial number of the module and the hardware identifier of the function
     * (for exemple: MyCustomName.relay1)
     * 
     * @return a string that uniquely identifies the function using logical names
     *         (ex: MyCustomName.relay1)
     * 
     * On failure, throws an exception or returns  Y_FRIENDLYNAME_INVALID.
     */
    virtual string      get_friendlyName(void);


    /**
     * Returns the number of functions (beside the "module" interface) available on the module.
     * 
     * @return the number of functions on the module
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             functionCount();
    
    /**
     * Retrieves the hardware identifier of the <i>n</i>th function on the module.
     * 
     * @param functionIndex : the index of the function for which the information is desired, starting at
     * 0 for the first function.
     * 
     * @return a string corresponding to the unambiguous hardware identifier of the requested module function
     * 
     * On failure, throws an exception or returns an empty string.
     */
    string          functionId(int functionIndex);
    
    /**
     * Retrieves the logical name of the <i>n</i>th function on the module.
     * 
     * @param functionIndex : the index of the function for which the information is desired, starting at
     * 0 for the first function.
     * 
     * @return a string corresponding to the logical name of the requested module function
     * 
     * On failure, throws an exception or returns an empty string.
     */
    string          functionName(int functionIndex);
    
    /**
     * Retrieves the advertised value of the <i>n</i>th function on the module.
     * 
     * @param functionIndex : the index of the function for which the information is desired, starting at
     * 0 for the first function.
     * 
     * @return a short string (up to 6 characters) corresponding to the advertised value of the requested
     * module function
     * 
     * On failure, throws an exception or returns an empty string.
     */
    string          functionValue(int functionIndex);
    
    void            setImmutableAttributes(yDeviceSt *infos);

    /**
     * todo
     * 
     * @param callback : the callback function to call, or a null pointer. The callback function should take two
     *         arguments: the function object of which the value has changed, and the character string describing
     *         the new advertised value.
     * @noreturn
     */
    void            registerLogCallback(YModuleLogCallback callback);

    
    YModuleLogCallback get_logCallback();
    
    

    //--- (generated code: YModule accessors declaration)

    static const string PRODUCTNAME_INVALID;
    static const string SERIALNUMBER_INVALID;
    static const int PRODUCTID_INVALID = YAPI_INVALID_UINT;
    static const int PRODUCTRELEASE_INVALID = YAPI_INVALID_UINT;
    static const string FIRMWARERELEASE_INVALID;
    static const Y_PERSISTENTSETTINGS_enum PERSISTENTSETTINGS_LOADED = Y_PERSISTENTSETTINGS_LOADED;
    static const Y_PERSISTENTSETTINGS_enum PERSISTENTSETTINGS_SAVED = Y_PERSISTENTSETTINGS_SAVED;
    static const Y_PERSISTENTSETTINGS_enum PERSISTENTSETTINGS_MODIFIED = Y_PERSISTENTSETTINGS_MODIFIED;
    static const Y_PERSISTENTSETTINGS_enum PERSISTENTSETTINGS_INVALID = Y_PERSISTENTSETTINGS_INVALID;
    static const int LUMINOSITY_INVALID = YAPI_INVALID_UINT;
    static const Y_BEACON_enum BEACON_OFF = Y_BEACON_OFF;
    static const Y_BEACON_enum BEACON_ON = Y_BEACON_ON;
    static const Y_BEACON_enum BEACON_INVALID = Y_BEACON_INVALID;
    static const s64 UPTIME_INVALID = YAPI_INVALID_LONG;
    static const int USBCURRENT_INVALID = YAPI_INVALID_UINT;
    static const int REBOOTCOUNTDOWN_INVALID = YAPI_INVALID_INT;
    static const Y_USBBANDWIDTH_enum USBBANDWIDTH_SIMPLE = Y_USBBANDWIDTH_SIMPLE;
    static const Y_USBBANDWIDTH_enum USBBANDWIDTH_DOUBLE = Y_USBBANDWIDTH_DOUBLE;
    static const Y_USBBANDWIDTH_enum USBBANDWIDTH_INVALID = Y_USBBANDWIDTH_INVALID;

    /**
     * Returns the commercial name of the module, as set by the factory.
     * 
     * @return a string corresponding to the commercial name of the module, as set by the factory
     * 
     * On failure, throws an exception or returns Y_PRODUCTNAME_INVALID.
     */
    string              get_productName(void);

    inline string       productName(void)
    { return this->get_productName(); }

    /**
     * Returns the serial number of the module, as set by the factory.
     * 
     * @return a string corresponding to the serial number of the module, as set by the factory
     * 
     * On failure, throws an exception or returns Y_SERIALNUMBER_INVALID.
     */
    string              get_serialNumber(void);

    inline string       serialNumber(void)
    { return this->get_serialNumber(); }

    /**
     * Returns the USB device identifier of the module.
     * 
     * @return an integer corresponding to the USB device identifier of the module
     * 
     * On failure, throws an exception or returns Y_PRODUCTID_INVALID.
     */
    int                 get_productId(void);

    inline int          productId(void)
    { return this->get_productId(); }

    /**
     * Returns the hardware release version of the module.
     * 
     * @return an integer corresponding to the hardware release version of the module
     * 
     * On failure, throws an exception or returns Y_PRODUCTRELEASE_INVALID.
     */
    int                 get_productRelease(void);

    inline int          productRelease(void)
    { return this->get_productRelease(); }

    /**
     * Returns the version of the firmware embedded in the module.
     * 
     * @return a string corresponding to the version of the firmware embedded in the module
     * 
     * On failure, throws an exception or returns Y_FIRMWARERELEASE_INVALID.
     */
    string              get_firmwareRelease(void);

    inline string       firmwareRelease(void)
    { return this->get_firmwareRelease(); }

    /**
     * Returns the current state of persistent module settings.
     * 
     * @return a value among Y_PERSISTENTSETTINGS_LOADED, Y_PERSISTENTSETTINGS_SAVED and
     * Y_PERSISTENTSETTINGS_MODIFIED corresponding to the current state of persistent module settings
     * 
     * On failure, throws an exception or returns Y_PERSISTENTSETTINGS_INVALID.
     */
    Y_PERSISTENTSETTINGS_enum get_persistentSettings(void);

    inline Y_PERSISTENTSETTINGS_enum persistentSettings(void)
    { return this->get_persistentSettings(); }

    int             set_persistentSettings(Y_PERSISTENTSETTINGS_enum newval);
    inline int      setPersistentSettings(Y_PERSISTENTSETTINGS_enum newval)
    { return this->set_persistentSettings(newval); }

    /**
     * Returns the luminosity of the  module informative leds (from 0 to 100).
     * 
     * @return an integer corresponding to the luminosity of the  module informative leds (from 0 to 100)
     * 
     * On failure, throws an exception or returns Y_LUMINOSITY_INVALID.
     */
    int                 get_luminosity(void);

    inline int          luminosity(void)
    { return this->get_luminosity(); }

    /**
     * Changes the luminosity of the module informative leds. The parameter is a
     * value between 0 and 100.
     * Remember to call the saveToFlash() method of the module if the
     * modification must be kept.
     * 
     * @param newval : an integer corresponding to the luminosity of the module informative leds
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_luminosity(int newval);
    inline int      setLuminosity(int newval)
    { return this->set_luminosity(newval); }

    /**
     * Returns the state of the localization beacon.
     * 
     * @return either Y_BEACON_OFF or Y_BEACON_ON, according to the state of the localization beacon
     * 
     * On failure, throws an exception or returns Y_BEACON_INVALID.
     */
    Y_BEACON_enum       get_beacon(void);

    inline Y_BEACON_enum beacon(void)
    { return this->get_beacon(); }

    /**
     * Turns on or off the module localization beacon.
     * 
     * @param newval : either Y_BEACON_OFF or Y_BEACON_ON
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_beacon(Y_BEACON_enum newval);
    inline int      setBeacon(Y_BEACON_enum newval)
    { return this->set_beacon(newval); }

    /**
     * Returns the number of milliseconds spent since the module was powered on.
     * 
     * @return an integer corresponding to the number of milliseconds spent since the module was powered on
     * 
     * On failure, throws an exception or returns Y_UPTIME_INVALID.
     */
    s64                 get_upTime(void);

    inline s64          upTime(void)
    { return this->get_upTime(); }

    /**
     * Returns the current consumed by the module on the USB bus, in milli-amps.
     * 
     * @return an integer corresponding to the current consumed by the module on the USB bus, in milli-amps
     * 
     * On failure, throws an exception or returns Y_USBCURRENT_INVALID.
     */
    int                 get_usbCurrent(void);

    inline int          usbCurrent(void)
    { return this->get_usbCurrent(); }

    /**
     * Returns the remaining number of seconds before the module restarts, or zero when no
     * reboot has been scheduled.
     * 
     * @return an integer corresponding to the remaining number of seconds before the module restarts, or zero when no
     *         reboot has been scheduled
     * 
     * On failure, throws an exception or returns Y_REBOOTCOUNTDOWN_INVALID.
     */
    int                 get_rebootCountdown(void);

    inline int          rebootCountdown(void)
    { return this->get_rebootCountdown(); }

    int             set_rebootCountdown(int newval);
    inline int      setRebootCountdown(int newval)
    { return this->set_rebootCountdown(newval); }

    /**
     * Returns the number of USB interfaces used by the module.
     * 
     * @return either Y_USBBANDWIDTH_SIMPLE or Y_USBBANDWIDTH_DOUBLE, according to the number of USB
     * interfaces used by the module
     * 
     * On failure, throws an exception or returns Y_USBBANDWIDTH_INVALID.
     */
    Y_USBBANDWIDTH_enum get_usbBandwidth(void);

    inline Y_USBBANDWIDTH_enum usbBandwidth(void)
    { return this->get_usbBandwidth(); }

    /**
     * Changes the number of USB interfaces used by the module. You must reboot the module
     * after changing this setting.
     * 
     * @param newval : either Y_USBBANDWIDTH_SIMPLE or Y_USBBANDWIDTH_DOUBLE, according to the number of
     * USB interfaces used by the module
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_usbBandwidth(Y_USBBANDWIDTH_enum newval);
    inline int      setUsbBandwidth(Y_USBBANDWIDTH_enum newval)
    { return this->set_usbBandwidth(newval); }

    /**
     * Allows you to find a module from its serial number or from its logical name.
     * 
     * This function does not require that the module is online at the time
     * it is invoked. The returned object is nevertheless valid.
     * Use the method YModule.isOnline() to test if the module is
     * indeed online at a given time. In case of ambiguity when looking for
     * a module by logical name, no error is notified: the first instance
     * found is returned. The search is performed first by hardware name,
     * then by logical name.
     * 
     * @param func : a string containing either the serial number or
     *         the logical name of the desired module
     * 
     * @return a YModule object allowing you to drive the module
     *         or get additional information on the module.
     */
    static YModule*     FindModule(string func);

    /**
     * Registers the callback function that is invoked on every change of advertised value.
     * The callback is invoked only during the execution of ySleep or yHandleEvents.
     * This provides control over the time when the callback is triggered. For good responsiveness, remember to call
     * one of these two functions periodically. To unregister a callback, pass a null pointer as argument.
     * 
     * @param callback : the callback function to call, or a null pointer. The callback function should take two
     *         arguments: the function object of which the value has changed, and the character string describing
     *         the new advertised value.
     * @noreturn
     */
    virtual int         registerValueCallback(YModuleValueCallback callback);
    using YFunction::registerValueCallback;

    virtual int         _invokeValueCallback(string value);

    /**
     * Saves current settings in the nonvolatile memory of the module.
     * Warning: the number of allowed save operations during a module life is
     * limited (about 100000 cycles). Do not call this function within a loop.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    virtual int         saveToFlash(void);

    /**
     * Reloads the settings stored in the nonvolatile memory, as
     * when the module is powered on.
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    virtual int         revertFromFlash(void);

    /**
     * Schedules a simple module reboot after the given number of seconds.
     * 
     * @param secBeforeReboot : number of seconds before rebooting
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    virtual int         reboot(int secBeforeReboot);

    /**
     * Schedules a module reboot into special firmware update mode.
     * 
     * @param secBeforeReboot : number of seconds before rebooting
     * 
     * @return YAPI_SUCCESS when the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    virtual int         triggerFirmwareUpdate(int secBeforeReboot);

    /**
     * Downloads the specified built-in file and returns a binary buffer with its content.
     * 
     * @param pathname : name of the new file to load
     * 
     * @return a binary buffer with the file content
     * 
     * On failure, throws an exception or returns an empty content.
     */
    virtual string      download(string pathname);

    /**
     * Returns the icon of the module. The icon is a PNG image and does not
     * exceeds 1536 bytes.
     * 
     * @return a binary buffer with module icon, in png format.
     */
    virtual string      get_icon2d(void);

    /**
     * Returns a string with last logs of the module. This method return only
     * logs that are still in the module.
     * 
     * @return a string with last logs of the module.
     */
    virtual string      get_lastLogs(void);


    inline static YModule* Find(string func)
    { return YModule::FindModule(func); }

    /**
     * Continues the module enumeration started using yFirstModule().
     * 
     * @return a pointer to a YModule object, corresponding to
     *         the next module found, or a null pointer
     *         if there are no more modules to enumerate.
     */
           YModule         *nextModule(void);
    inline YModule         *next(void)
    { return this->nextModule();}

    /**
     * Starts the enumeration of modules currently accessible.
     * Use the method YModule.nextModule() to iterate on the
     * next modules.
     * 
     * @return a pointer to a YModule object, corresponding to
     *         the first module currently online, or a null pointer
     *         if there are none.
     */
           static YModule* FirstModule(void);
    inline static YModule* First(void)
    { return YModule::FirstModule();}
    //--- (end of generated code: YModule accessors declaration)
};




//--- (generated code: YSensor declaration)
/**
 * YSensor Class: Sensor function interface
 * 
 * The Yoctopuce application programming interface allows you to read an instant
 * measure of the sensor, as well as the minimal and maximal values observed.
 */
class YOCTO_CLASS_EXPORT YSensor: public YFunction {
//--- (end of generated code: YSensor declaration)
protected:
    //--- (generated code: YSensor attributes)
    // Attributes (function value cache)
    string          _unit;
    double          _currentValue;
    double          _lowestValue;
    double          _highestValue;
    double          _currentRawValue;
    string          _logFrequency;
    string          _reportFrequency;
    string          _calibrationParam;
    double          _resolution;
    YSensorValueCallback _valueCallbackSensor;
    YSensorTimedReportCallback _timedReportCallbackSensor;
    double          _prevTimedReport;
    double          _iresol;
    double          _offset;
    double          _scale;
    double          _decexp;
    bool            _isScal;
    int             _caltyp;
    vector<int>     _calpar;
    vector<double>  _calraw;
    vector<double>  _calref;
    yCalibrationHandler _calhdl;

    friend YSensor *yFindSensor(const string& func);
    friend YSensor *yFirstSensor(void);

    // Function-specific method for parsing of JSON output and caching result
    virtual int     _parseAttr(yJsonStateMachine& j);

    // Constructor is protected, use yFindSensor factory function to instantiate
    YSensor(const string& func);
    //--- (end of generated code: YSensor attributes)

    //--- (generated code: Sensor initialization)
    //--- (end of generated code: Sensor initialization)

    // Method used to encode calibration points into fixed-point 16-bit integers
    string      _encodeCalibrationPoints(const floatArr& rawValues, const floatArr& refValues, const string& actualCparams);
    
    // Method used to decode calibration points from fixed-point 16-bit integers
    int         _decodeCalibrationPoints(const string& calibParams,intArr& iParams, floatArr& rawPt, floatArr& calPt);
    
public:
    ~YSensor();
    //--- (generated code: YSensor accessors declaration)

    static const string UNIT_INVALID;
    static const double CURRENTVALUE_INVALID;
    static const double LOWESTVALUE_INVALID;
    static const double HIGHESTVALUE_INVALID;
    static const double CURRENTRAWVALUE_INVALID;
    static const string LOGFREQUENCY_INVALID;
    static const string REPORTFREQUENCY_INVALID;
    static const string CALIBRATIONPARAM_INVALID;
    static const double RESOLUTION_INVALID;

    /**
     * Returns the measuring unit for the measure.
     * 
     * @return a string corresponding to the measuring unit for the measure
     * 
     * On failure, throws an exception or returns Y_UNIT_INVALID.
     */
    string              get_unit(void);

    inline string       unit(void)
    { return this->get_unit(); }

    /**
     * Returns the current value of the measure.
     * 
     * @return a floating point number corresponding to the current value of the measure
     * 
     * On failure, throws an exception or returns Y_CURRENTVALUE_INVALID.
     */
    double              get_currentValue(void);

    inline double       currentValue(void)
    { return this->get_currentValue(); }

    /**
     * Changes the recorded minimal value observed.
     * 
     * @param newval : a floating point number corresponding to the recorded minimal value observed
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_lowestValue(double newval);
    inline int      setLowestValue(double newval)
    { return this->set_lowestValue(newval); }

    /**
     * Returns the minimal value observed for the measure since the device was started.
     * 
     * @return a floating point number corresponding to the minimal value observed for the measure since
     * the device was started
     * 
     * On failure, throws an exception or returns Y_LOWESTVALUE_INVALID.
     */
    double              get_lowestValue(void);

    inline double       lowestValue(void)
    { return this->get_lowestValue(); }

    /**
     * Changes the recorded maximal value observed.
     * 
     * @param newval : a floating point number corresponding to the recorded maximal value observed
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_highestValue(double newval);
    inline int      setHighestValue(double newval)
    { return this->set_highestValue(newval); }

    /**
     * Returns the maximal value observed for the measure since the device was started.
     * 
     * @return a floating point number corresponding to the maximal value observed for the measure since
     * the device was started
     * 
     * On failure, throws an exception or returns Y_HIGHESTVALUE_INVALID.
     */
    double              get_highestValue(void);

    inline double       highestValue(void)
    { return this->get_highestValue(); }

    /**
     * Returns the uncalibrated, unrounded raw value returned by the sensor.
     * 
     * @return a floating point number corresponding to the uncalibrated, unrounded raw value returned by the sensor
     * 
     * On failure, throws an exception or returns Y_CURRENTRAWVALUE_INVALID.
     */
    double              get_currentRawValue(void);

    inline double       currentRawValue(void)
    { return this->get_currentRawValue(); }

    /**
     * Returns the datalogger recording frequency for this function, or "OFF"
     * when measures are not stored in the data logger flash memory.
     * 
     * @return a string corresponding to the datalogger recording frequency for this function, or "OFF"
     *         when measures are not stored in the data logger flash memory
     * 
     * On failure, throws an exception or returns Y_LOGFREQUENCY_INVALID.
     */
    string              get_logFrequency(void);

    inline string       logFrequency(void)
    { return this->get_logFrequency(); }

    /**
     * Changes the datalogger recording frequency for this function.
     * The frequency can be specified as samples per second,
     * as sample per minute (for instance "15/m") or in samples per
     * hour (eg. "4/h"). To disable recording for this function, use
     * the value "OFF".
     * 
     * @param newval : a string corresponding to the datalogger recording frequency for this function
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_logFrequency(const string& newval);
    inline int      setLogFrequency(const string& newval)
    { return this->set_logFrequency(newval); }

    /**
     * Returns the timed value notification frequency, or "OFF" if timed
     * value notifications are disabled for this function.
     * 
     * @return a string corresponding to the timed value notification frequency, or "OFF" if timed
     *         value notifications are disabled for this function
     * 
     * On failure, throws an exception or returns Y_REPORTFREQUENCY_INVALID.
     */
    string              get_reportFrequency(void);

    inline string       reportFrequency(void)
    { return this->get_reportFrequency(); }

    /**
     * Changes the timed value notification frequency for this function.
     * The frequency can be specified as samples per second,
     * as sample per minute (for instance "15/m") or in samples per
     * hour (eg. "4/h"). To disable timed value notifications for this
     * function, use the value "OFF".
     * 
     * @param newval : a string corresponding to the timed value notification frequency for this function
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_reportFrequency(const string& newval);
    inline int      setReportFrequency(const string& newval)
    { return this->set_reportFrequency(newval); }

    string              get_calibrationParam(void);

    inline string       calibrationParam(void)
    { return this->get_calibrationParam(); }

    int             set_calibrationParam(const string& newval);
    inline int      setCalibrationParam(const string& newval)
    { return this->set_calibrationParam(newval); }

    /**
     * Changes the resolution of the measured physical values. The resolution corresponds to the numerical precision
     * when displaying value. It does not change the precision of the measure itself.
     * 
     * @param newval : a floating point number corresponding to the resolution of the measured physical values
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    int             set_resolution(double newval);
    inline int      setResolution(double newval)
    { return this->set_resolution(newval); }

    /**
     * Returns the resolution of the measured values. The resolution corresponds to the numerical precision
     * of the measures, which is not always the same as the actual precision of the sensor.
     * 
     * @return a floating point number corresponding to the resolution of the measured values
     * 
     * On failure, throws an exception or returns Y_RESOLUTION_INVALID.
     */
    double              get_resolution(void);

    inline double       resolution(void)
    { return this->get_resolution(); }

    /**
     * Retrieves a sensor for a given identifier.
     * The identifier can be specified using several formats:
     * <ul>
     * <li>FunctionLogicalName</li>
     * <li>ModuleSerialNumber.FunctionIdentifier</li>
     * <li>ModuleSerialNumber.FunctionLogicalName</li>
     * <li>ModuleLogicalName.FunctionIdentifier</li>
     * <li>ModuleLogicalName.FunctionLogicalName</li>
     * </ul>
     * 
     * This function does not require that the sensor is online at the time
     * it is invoked. The returned object is nevertheless valid.
     * Use the method YSensor.isOnline() to test if the sensor is
     * indeed online at a given time. In case of ambiguity when looking for
     * a sensor by logical name, no error is notified: the first instance
     * found is returned. The search is performed first by hardware name,
     * then by logical name.
     * 
     * @param func : a string that uniquely characterizes the sensor
     * 
     * @return a YSensor object allowing you to drive the sensor.
     */
    static YSensor*     FindSensor(string func);

    /**
     * Registers the callback function that is invoked on every change of advertised value.
     * The callback is invoked only during the execution of ySleep or yHandleEvents.
     * This provides control over the time when the callback is triggered. For good responsiveness, remember to call
     * one of these two functions periodically. To unregister a callback, pass a null pointer as argument.
     * 
     * @param callback : the callback function to call, or a null pointer. The callback function should take two
     *         arguments: the function object of which the value has changed, and the character string describing
     *         the new advertised value.
     * @noreturn
     */
    virtual int         registerValueCallback(YSensorValueCallback callback);
    using YFunction::registerValueCallback;

    virtual int         _invokeValueCallback(string value);

    virtual int         _parserHelper(void);

    /**
     * Retrieves a DataSet object holding historical data for this
     * sensor, for a specified time interval. The measures will be
     * retrieved from the data logger, which must have been turned
     * on at the desired time. See the documentation of the DataSet
     * class for information on how to get an overview of the
     * recorded data, and how to load progressively a large set
     * of measures from the data logger.
     * 
     * This function only works if the device uses a recent firmware,
     * as DataSet objects are not supported by firmwares older than
     * version 13000.
     * 
     * @param startTime : the start of the desired measure time interval,
     *         as a Unix timestamp, i.e. the number of seconds since
     *         January 1, 1970 UTC. The special value 0 can be used
     *         to include any meaasure, without initial limit.
     * @param endTime : the end of the desired measure time interval,
     *         as a Unix timestamp, i.e. the number of seconds since
     *         January 1, 1970 UTC. The special value 0 can be used
     *         to include any meaasure, without ending limit.
     * 
     * @return an instance of YDataSet, providing access to historical
     *         data. Past measures can be loaded progressively
     *         using methods from the YDataSet object.
     */
    virtual YDataSet    get_recordedData(s64 startTime,s64 endTime);

    /**
     * Registers the callback function that is invoked on every periodic timed notification.
     * The callback is invoked only during the execution of ySleep or yHandleEvents.
     * This provides control over the time when the callback is triggered. For good responsiveness, remember to call
     * one of these two functions periodically. To unregister a callback, pass a null pointer as argument.
     * 
     * @param callback : the callback function to call, or a null pointer. The callback function should take two
     *         arguments: the function object of which the value has changed, and an YMeasure object describing
     *         the new advertised value.
     * @noreturn
     */
    virtual int         registerTimedReportCallback(YSensorTimedReportCallback callback);

    virtual int         _invokeTimedReportCallback(YMeasure value);

    /**
     * Configures error correction data points, in particular to compensate for
     * a possible perturbation of the measure caused by an enclosure. It is possible
     * to configure up to five correction points. Correction points must be provided
     * in ascending order, and be in the range of the sensor. The device will automatically
     * perform a linear interpolation of the error correction between specified
     * points. Remember to call the saveToFlash() method of the module if the
     * modification must be kept.
     * 
     * For more information on advanced capabilities to refine the calibration of
     * sensors, please contact support@yoctopuce.com.
     * 
     * @param rawValues : array of floating point numbers, corresponding to the raw
     *         values returned by the sensor for the correction points.
     * @param refValues : array of floating point numbers, corresponding to the corrected
     *         values for the correction points.
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    virtual int         calibrateFromPoints(vector<double> rawValues,vector<double> refValues);

    /**
     * Retrieves error correction data points previously entered using the method
     * calibrateFromPoints.
     * 
     * @param rawValues : array of floating point numbers, that will be filled by the
     *         function with the raw sensor values for the correction points.
     * @param refValues : array of floating point numbers, that will be filled by the
     *         function with the desired values for the correction points.
     * 
     * @return YAPI_SUCCESS if the call succeeds.
     * 
     * On failure, throws an exception or returns a negative error code.
     */
    virtual int         loadCalibrationPoints(vector<double>& rawValues,vector<double>& refValues);

    virtual string      _encodeCalibrationPoints(vector<double> rawValues,vector<double> refValues);

    virtual double      _applyCalibration(double rawValue);

    virtual YMeasure    _decodeTimedReport(double timestamp,vector<int> report);

    virtual double      _decodeVal(int w);

    virtual double      _decodeAvg(int dw);


    inline static YSensor* Find(string func)
    { return YSensor::FindSensor(func); }

    /**
     * Continues the enumeration of sensors started using yFirstSensor().
     * 
     * @return a pointer to a YSensor object, corresponding to
     *         a sensor currently online, or a null pointer
     *         if there are no more sensors to enumerate.
     */
           YSensor         *nextSensor(void);
    inline YSensor         *next(void)
    { return this->nextSensor();}

    /**
     * Starts the enumeration of sensors currently accessible.
     * Use the method YSensor.nextSensor() to iterate on
     * next sensors.
     * 
     * @return a pointer to a YSensor object, corresponding to
     *         the first sensor currently online, or a null pointer
     *         if there are none.
     */
           static YSensor* FirstSensor(void);
    inline static YSensor* First(void)
    { return YSensor::FirstSensor();}
    //--- (end of generated code: YSensor accessors declaration)
};

//--- (generated code: Sensor functions declaration)

/**
 * Retrieves a sensor for a given identifier.
 * The identifier can be specified using several formats:
 * <ul>
 * <li>FunctionLogicalName</li>
 * <li>ModuleSerialNumber.FunctionIdentifier</li>
 * <li>ModuleSerialNumber.FunctionLogicalName</li>
 * <li>ModuleLogicalName.FunctionIdentifier</li>
 * <li>ModuleLogicalName.FunctionLogicalName</li>
 * </ul>
 * 
 * This function does not require that the sensor is online at the time
 * it is invoked. The returned object is nevertheless valid.
 * Use the method YSensor.isOnline() to test if the sensor is
 * indeed online at a given time. In case of ambiguity when looking for
 * a sensor by logical name, no error is notified: the first instance
 * found is returned. The search is performed first by hardware name,
 * then by logical name.
 * 
 * @param func : a string that uniquely characterizes the sensor
 * 
 * @return a YSensor object allowing you to drive the sensor.
 */
inline YSensor* yFindSensor(const string& func)
{ return YSensor::FindSensor(func);}
/**
 * Starts the enumeration of sensors currently accessible.
 * Use the method YSensor.nextSensor() to iterate on
 * next sensors.
 * 
 * @return a pointer to a YSensor object, corresponding to
 *         the first sensor currently online, or a null pointer
 *         if there are none.
 */
inline YSensor* yFirstSensor(void)
{ return YSensor::FirstSensor();}

//--- (end of generated code: Sensor functions declaration)


inline string yGetAPIVersion() 
{ return YAPI::GetAPIVersion(); }



/**
 * Initializes the Yoctopuce programming library explicitly.
 * It is not strictly needed to call yInitAPI(), as the library is
 * automatically  initialized when calling yRegisterHub() for the
 * first time.
 * 
 * When Y_DETECT_NONE is used as detection mode,
 * you must explicitly use yRegisterHub() to point the API to the
 * VirtualHub on which your devices are connected before trying to access them.
 * 
 * @param mode : an integer corresponding to the type of automatic
 *         device detection to use. Possible values are
 *         Y_DETECT_NONE, Y_DETECT_USB, Y_DETECT_NET,
 *         and Y_DETECT_ALL.
 * @param errmsg : a string passed by reference to receive any error message.
 * 
 * @return YAPI_SUCCESS when the call succeeds.
 * 
 * On failure, throws an exception or returns a negative error code.
 */
inline YRETCODE yInitAPI(int mode, string& errmsg) 
{ return YAPI::InitAPI(mode,errmsg); }

/**
 * Frees dynamically allocated memory blocks used by the Yoctopuce library.
 * It is generally not required to call this function, unless you
 * want to free all dynamically allocated memory blocks in order to
 * track a memory leak for instance.
 * You should not call any other library function after calling
 * yFreeAPI(), or your program will crash.
 */
inline void yFreeAPI() 
{ YAPI::FreeAPI(); }

/**
 * Disables the use of exceptions to report runtime errors.
 * When exceptions are disabled, every function returns a specific
 * error value which depends on its type and which is documented in
 * this reference manual.
 */
inline void yDisableExceptions(void) 
{ YAPI::DisableExceptions(); }

/**
 * Re-enables the use of exceptions for runtime error handling.
 * Be aware than when exceptions are enabled, every function that fails
 * triggers an exception. If the exception is not caught by the user code,
 * it  either fires the debugger or aborts (i.e. crash) the program.
 * On failure, throws an exception or returns a negative error code.
 */
inline void yEnableExceptions(void)  
{ YAPI::EnableExceptions(); }

/**
 * Registers a log callback function. This callback will be called each time
 * the API have something to say. Quite useful to debug the API.
 * 
 * @param logfun : a procedure taking a string parameter, or null
 *         to unregister a previously registered  callback.
 */
inline void yRegisterLogFunction(yLogFunction logfun)                               
{ YAPI::RegisterLogFunction(logfun); }

/**
 * Register a callback function, to be called each time
 * a device is plugged. This callback will be invoked while yUpdateDeviceList
 * is running. You will have to call this function on a regular basis.
 * 
 * @param arrivalCallback : a procedure taking a YModule parameter, or null
 *         to unregister a previously registered  callback.
 */
inline void yRegisterDeviceArrivalCallback(yDeviceUpdateCallback arrivalCallback)   
{ YAPI::RegisterDeviceArrivalCallback(arrivalCallback); }

/**
 * Register a callback function, to be called each time
 * a device is unplugged. This callback will be invoked while yUpdateDeviceList
 * is running. You will have to call this function on a regular basis.
 * 
 * @param removalCallback : a procedure taking a YModule parameter, or null
 *         to unregister a previously registered  callback.
 */
inline void yRegisterDeviceRemovalCallback(yDeviceUpdateCallback removalCallback)   
{ YAPI::RegisterDeviceRemovalCallback(removalCallback); }

inline void yRegisterDeviceChangeCallback(yDeviceUpdateCallback removalCallback)    
{ YAPI::RegisterDeviceChangeCallback(removalCallback); }


/**
 * Register a callback function, to be called each time an Network Hub send
 * an SSDP message. The callback has two string parameter, the first one
 * contain the serial number of the hub and the second contain the URL of the
 * network hub (this URL can be passed to RegisterHub). This callback will be invoked
 * while yUpdateDeviceList is running. You will have to call this function on a regular basis.
 * 
 * @param hubDiscoveryCallback : a procedure taking two string parameter, or null
 *         to unregister a previously registered  callback.
 */
inline void yRegisterHubDiscoveryCallback(YHubDiscoveryCallback hubDiscoveryCallback)
{
	YAPI::RegisterHubDiscoveryCallback(hubDiscoveryCallback);
}

/**
 * Force a hub discovery, if a callback as been registered with yRegisterDeviceRemovalCallback it
 * will be called for each net work hub that will respond to the discovery.
 * 
 * @param errmsg : a string passed by reference to receive any error message.
 * 
 * @return YAPI_SUCCESS when the call succeeds.
 *         On failure, throws an exception or returns a negative error code.
 */
inline YRETCODE yTriggerHubDiscovery(string& errmsg)
{
	return YAPI::TriggerHubDiscovery(errmsg);
}


// Register a new value calibration handler for a given calibration type
//
inline void yRegisterCalibrationHandler(int calibrationType, yCalibrationHandler calibrationHandler)
{ YAPI::RegisterCalibrationHandler(calibrationType, calibrationHandler); }

/**
 * Setup the Yoctopuce library to use modules connected on a given machine. The
 * parameter will determine how the API will work. Use the following values:
 * 
 * <b>usb</b>: When the usb keyword is used, the API will work with
 * devices connected directly to the USB bus. Some programming languages such a Javascript,
 * PHP, and Java don't provide direct access to USB hardware, so usb will
 * not work with these. In this case, use a VirtualHub or a networked YoctoHub (see below).
 * 
 * <b><i>x.x.x.x</i></b> or <b><i>hostname</i></b>: The API will use the devices connected to the
 * host with the given IP address or hostname. That host can be a regular computer
 * running a VirtualHub, or a networked YoctoHub such as YoctoHub-Ethernet or
 * YoctoHub-Wireless. If you want to use the VirtualHub running on you local
 * computer, use the IP address 127.0.0.1.
 * 
 * <b>callback</b>: that keyword make the API run in "<i>HTTP Callback</i>" mode.
 * This a special mode allowing to take control of Yoctopuce devices
 * through a NAT filter when using a VirtualHub or a networked YoctoHub. You only
 * need to configure your hub to call your server script on a regular basis.
 * This mode is currently available for PHP and Node.JS only.
 * 
 * Be aware that only one application can use direct USB access at a
 * given time on a machine. Multiple access would cause conflicts
 * while trying to access the USB modules. In particular, this means
 * that you must stop the VirtualHub software before starting
 * an application that uses direct USB access. The workaround
 * for this limitation is to setup the library to use the VirtualHub
 * rather than direct USB access.
 * 
 * If access control has been activated on the hub, virtual or not, you want to
 * reach, the URL parameter should look like:
 * 
 * http://username:password@adresse:port
 * 
 * You can call <i>RegisterHub</i> several times to connect to several machines.
 * 
 * @param url : a string containing either "usb","callback" or the
 *         root URL of the hub to monitor
 * @param errmsg : a string passed by reference to receive any error message.
 * 
 * @return YAPI_SUCCESS when the call succeeds.
 * 
 * On failure, throws an exception or returns a negative error code.
 */
inline YRETCODE yRegisterHub(const string& url, string& errmsg) 
{ return YAPI::RegisterHub(url,errmsg); }

/**
 * Fault-tolerant alternative to RegisterHub(). This function has the same
 * purpose and same arguments as RegisterHub(), but does not trigger
 * an error when the selected hub is not available at the time of the function call.
 * This makes it possible to register a network hub independently of the current
 * connectivity, and to try to contact it only when a device is actively needed.
 * 
 * @param url : a string containing either "usb","callback" or the
 *         root URL of the hub to monitor
 * @param errmsg : a string passed by reference to receive any error message.
 * 
 * @return YAPI_SUCCESS when the call succeeds.
 * 
 * On failure, throws an exception or returns a negative error code.
 */
inline YRETCODE yPreregisterHub(const string& url, string& errmsg) 
{ return YAPI::PreregisterHub(url,errmsg); }

/**
 * Setup the Yoctopuce library to no more use modules connected on a previously
 * registered machine with RegisterHub.
 * 
 * @param url : a string containing either "usb" or the
 *         root URL of the hub to monitor
 */
inline void yUnregisterHub(const string& url) 
{ YAPI::UnregisterHub(url); }



/**
 * Triggers a (re)detection of connected Yoctopuce modules.
 * The library searches the machines or USB ports previously registered using
 * yRegisterHub(), and invokes any user-defined callback function
 * in case a change in the list of connected devices is detected.
 * 
 * This function can be called as frequently as desired to refresh the device list
 * and to make the application aware of hot-plug events.
 * 
 * @param errmsg : a string passed by reference to receive any error message.
 * 
 * @return YAPI_SUCCESS when the call succeeds.
 * 
 * On failure, throws an exception or returns a negative error code.
 */
inline YRETCODE yUpdateDeviceList(string& errmsg) 
{ return YAPI::UpdateDeviceList(errmsg); }

/**
 * Maintains the device-to-library communication channel.
 * If your program includes significant loops, you may want to include
 * a call to this function to make sure that the library takes care of
 * the information pushed by the modules on the communication channels.
 * This is not strictly necessary, but it may improve the reactivity
 * of the library for the following commands.
 * 
 * This function may signal an error in case there is a communication problem
 * while contacting a module.
 * 
 * @param errmsg : a string passed by reference to receive any error message.
 * 
 * @return YAPI_SUCCESS when the call succeeds.
 * 
 * On failure, throws an exception or returns a negative error code.
 */
inline YRETCODE yHandleEvents(string& errmsg)
{ return YAPI::HandleEvents(errmsg); }

/**
 * Pauses the execution flow for a specified duration.
 * This function implements a passive waiting loop, meaning that it does not
 * consume CPU cycles significantly. The processor is left available for
 * other threads and processes. During the pause, the library nevertheless
 * reads from time to time information from the Yoctopuce modules by
 * calling yHandleEvents(), in order to stay up-to-date.
 * 
 * This function may signal an error in case there is a communication problem
 * while contacting a module.
 * 
 * @param ms_duration : an integer corresponding to the duration of the pause,
 *         in milliseconds.
 * @param errmsg : a string passed by reference to receive any error message.
 * 
 * @return YAPI_SUCCESS when the call succeeds.
 * 
 * On failure, throws an exception or returns a negative error code.
 */
inline YRETCODE ySleep(unsigned ms_duration, string& errmsg)
{ return YAPI::Sleep(ms_duration, errmsg); }

/**
 * Returns the current value of a monotone millisecond-based time counter.
 * This counter can be used to compute delays in relation with
 * Yoctopuce devices, which also uses the millisecond as timebase.
 * 
 * @return a long integer corresponding to the millisecond counter.
 */
inline u64 yGetTickCount(void)
{ return YAPI::GetTickCount(); }

/**
 * Checks if a given string is valid as logical name for a module or a function.
 * A valid logical name has a maximum of 19 characters, all among
 * A..Z, a..z, 0..9, _, and -.
 * If you try to configure a logical name with an incorrect string,
 * the invalid characters are ignored.
 * 
 * @param name : a string containing the name to check.
 * 
 * @return true if the name is valid, false otherwise.
 */
inline bool yCheckLogicalName(const string& name)
{ return YAPI::CheckLogicalName(name); }

//--- (generated code: Module functions declaration)

/**
 * Allows you to find a module from its serial number or from its logical name.
 * 
 * This function does not require that the module is online at the time
 * it is invoked. The returned object is nevertheless valid.
 * Use the method YModule.isOnline() to test if the module is
 * indeed online at a given time. In case of ambiguity when looking for
 * a module by logical name, no error is notified: the first instance
 * found is returned. The search is performed first by hardware name,
 * then by logical name.
 * 
 * @param func : a string containing either the serial number or
 *         the logical name of the desired module
 * 
 * @return a YModule object allowing you to drive the module
 *         or get additional information on the module.
 */
inline YModule* yFindModule(const string& func)
{ return YModule::FindModule(func);}
/**
 * Starts the enumeration of modules currently accessible.
 * Use the method YModule.nextModule() to iterate on the
 * next modules.
 * 
 * @return a pointer to a YModule object, corresponding to
 *         the first module currently online, or a null pointer
 *         if there are none.
 */
inline YModule* yFirstModule(void)
{ return YModule::FirstModule();}

//--- (end of generated code: Module functions declaration)


#endif
