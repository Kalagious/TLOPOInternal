<h2>Good Hooks</h2>
```c++
/* These would allow monitoring of all dictionary interactions and would allow for manual dictionary interactions 
Since all variables (except members) are in dictionaries, these two functions have to be used to access all variables */
PyDict_SetItem(PyObject* pDictObject, PyObject* pKeyName, PyObject* pValue);
PyDict_GetItem(PyObject* pDictObject, PyObject* pKeyName);

/* Basically PyDict_GetItem but for f_locals within a frame object, it is used for getting function objects, could be used to map out frame addresses */
__pypperoni_IMPL_load_name(PyObject* pFrame, PyObject* pKeyName);

/* This is the function that is used to call all python functions, hooking it would show all function calls and allow for stack modification before the function is called */
__pypperoni_IMPL_call_func(PyObject** stack_pointer, uint32_t argCount, PyObject**? pKwargs);

/* Would show eveytime an objects attribute is accessed */
PyObject_GetAttr(PyObject* pClassInstance, PyObject* pAttributeName);

```