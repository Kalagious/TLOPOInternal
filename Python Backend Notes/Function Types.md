***Note:***
```c++
/* Function objects and code objects should not be confused with each other:
 *
 * Function objects are created by the execution of the 'def' statement.
 * They reference a code object in their __code__ attribute, which is a
 * purely syntactic object, i.e. nothing more than a compiled version of some
 * source code lines.  There is one code object per source code "fragment",
 * but each code object can be referenced by zero or many function objects
 * depending only on how many times the 'def' statement in the source was
 * executed so far.
 */
```

<h2> PyCodeObject</h2>
```c++
struct PyCodeObject {                                                    
    PyObject_VAR_HEAD                                                          
                                                                               
    /* Note only the following fields are used in hash and/or comparisons      
     *                                                                         
     * - co_name                                                               
     * - co_argcount                                                           
     * - co_posonlyargcount                                                    
     * - co_kwonlyargcount                                                     
     * - co_nlocals                                                            
     * - co_stacksize                                                          
     * - co_flags                                                              
     * - co_firstlineno                                                        
     * - co_consts                                                             
     * - co_names                                                              
     * - co_localsplusnames                                                    
     * This is done to preserve the name and line number for tracebacks        
     * and debuggers; otherwise, constant de-duplication would collapse        
     * identical functions/lambdas defined on different lines.                 
     */                                                                        
                                                                               
    /* These fields are set with provided values on new code objects. */       
                                                                               
    /* The hottest fields (in the eval loop) are grouped here at the top. */   
    PyObject *co_consts;           /* list (constants used) */                 
    PyObject *co_names;            /* list of strings (names used) */          
    PyObject *co_exceptiontable;   /* Byte string encoding exception handling  
                                      table */                                 
    int co_flags;                  /* CO_..., see below */                     
    short co_warmup;                 /* Warmup counter for quickening */       
    short _co_linearray_entry_size;  /* Size of each entry in _co_linearray */ 
                                                                               
    /* The rest are not so impactful on performance. */                        
    int co_argcount;              /* #arguments, except *args */               
    int co_posonlyargcount;       /* #positional only arguments */             
    int co_kwonlyargcount;        /* #keyword only arguments */                
    int co_stacksize;             /* #entries needed for evaluation stack */   
    int co_firstlineno;           /* first source line number */               
                                                                               
    /* redundant values (derived from co_localsplusnames and                   
       co_localspluskinds) */                                                  
    int co_nlocalsplus;           /* number of local + cell + free variables */
    int co_framesize;             /* Size of frame in words */                 
    int co_nlocals;               /* number of local variables */              
    int co_nplaincellvars;        /* number of non-arg cell variables */       
    int co_ncellvars;             /* total number of cell variables */         
    int co_nfreevars;             /* number of free variables */               
                                                                               
    PyObject *co_localsplusnames; /* tuple mapping offsets to names */         
    PyObject *co_localspluskinds; /* Bytes mapping to local kinds (one byte    
                                     per variable) */                          
    PyObject *co_filename;        /* unicode (where it was loaded from) */     
    PyObject *co_name;            /* unicode (name, for reference) */          
    PyObject *co_qualname;        /* unicode (qualname, for reference) */      
    PyObject *co_linetable;       /* bytes object that holds location info */  
    PyObject *co_weakreflist;     /* to support weakrefs to code objects */    
    PyObject *_co_code;           /* cached co_code object/attribute */        
    int _co_firsttraceable;       /* index of first traceable instruction */   
    char *_co_linearray;          /* array of line offsets */                  
                          
    void *co_extra;                                                            
    char co_code_adaptive[1];                                             
}
```

<h2> PyFunctionObject</h2>
```c++
typedef struct {
    PyObject_HEAD
    PyObject func_globals; 
    PyObject func_builtins; 
    PyObject func_name; 
    PyObject func_qualname; 
    PyObject func_code;        /* A code object, the __code__ attribute */ 
    PyObject func_defaults;    /* NULL or a tuple */ 
    PyObject func_kwdefaults;  /* NULL or a dict */ 
    PyObject func_closure;     /* NULL or a tuple of cell objects */
    PyObject *func_doc;         /* The __doc__ attribute, can be anything */
    PyObject *func_dict;        /* The __dict__ attribute, a dict or NULL */
    PyObject *func_weakreflist; /* List of weak references */
    PyObject *func_module;      /* The __module__ attribute, can be anything */
    PyObject *func_annotations; /* Annotations, a dict or NULL */
    vectorcallfunc vectorcall;
    uint32_t func_version;
} PyFunctionObject;
```