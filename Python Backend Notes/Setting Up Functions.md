<h2>Setting up the hello_world(a, b) function</h2>
```python
def hello_world(a, b):
    x = [ 5 ]
    x.append(a)
    x.append(b)
    print(x)

hello_world(6, 7)

```



1. Function name is loaded from consts and pushed to the stack
```c++
PyStringObject* x = __consts_main[0]; /* 'hello_world' */
    Py_INCREF(x);
    PUSH(x);
```

2. A code object is created using the function parameters and PyCode_New()
```c++
PyCodeObject* codeobj = PyCode_New(
      2, /* argcount */
      0, /* kwonlyargcount */
      3, /* nlocals */
      2, /* stacksize */
      67, /* flags */
      NULL, /* code */
      NULL, /* consts */
      NULL, /* names */
      __consts_main[1], /* varnames */
      __consts_main[2], /* freevars */
      __consts_main[3], /* cellvars */
      __consts_main[4], /* filename */
      __consts_main[5], /* name */
      1, /* firstlineno */
      tmp /* lnotab */
    );
```

3. The function name is popped from the stack and combined with the codeobject to create a new PyFunctionObject
```c++

u = POP(); /* qualname */

PyFunctionObject* func = (PyFunctionObject*) PyFunction_NewWithQualName((PyObject*)codeobj, f->f_globals, u);
```

4. The co_meth_ptr member of the codeobj referenced by the functionobject is set to a pointer of the actual c++ function that the function object represents, the completed function object is then pushed to the stack
```c++
    codeobj->co_meth_ptr = &_main__module_4_hello_world_8_2_4__;
    PUSH((PyObject*)func);
```

5. The function object is then popped off the stack. The f_locals dictionary is pulled out of the frame passed at the beginning of the function, and the function object is added to the dictionary under the key of its name for later use. This is the end of the function setup
```c++
func = POP(); 
frame_locals = f->f_locals;
u = __consts_main[9]; // String name of fuction "hello_world"

PyDict_SetItem(frame_locals, u, func)

// "The hello_world" key is now in frame_locals pointing to the function object
```


<h2>Complete Code Flow</h2>
```c++
x = __consts_main[0]; /* 'hello_world' */
PUSH(x);
u = POP(); /* qualname */

tmp = PyBytes_FromString("");
codeobj = PyCode_New(
  2, /* argcount */
  0, /* kwonlyargcount */
  2, /* nlocals */
  2, /* stacksize */
  67, /* flags */
  NULL, /* code */
  NULL, /* consts */
  NULL, /* names */
  __consts_main[1], /* varnames */
  __consts_main[2], /* freevars */
  __consts_main[3], /* cellvars */
  __consts_main[4], /* filename */
  __consts_main[5], /* name */
  1, /* firstlineno */
  tmp /* lnotab */
);

func = (PyFunctionObject*) PyFunction_NewWithQualName((PyObject*)codeobj, f->f_globals, u);

codeobj->co_meth_ptr = &_main__module_4_hello_world_8_2_4__;
PUSH((PyObject*)func);
  
func = POP();
frame_locals = f->f_locals;

u = __consts_main[9];
PyDict_SetItem(frame_locals, u, func);
```