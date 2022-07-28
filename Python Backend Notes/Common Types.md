Type structs are stored in /cpython/include/cpython

<h2>Int(Long)</h2>
0-255 are predefined at run time
<h2>Float</h2>
```c++
typedef struct {
    Py_ssize_t ob_refcnt;
    PyTypeObject *ob_type;
    PyObject ob_base;
    double ob_fval;
} PyFloatObject;
```
<h2>String (PyBytesObject)</h2>
```c++

typedef struct {
    PyObject ob_base;
    Py_ssize_t ob_size;
    Py_hash_t ob_shash;
    char ob_sval[1];

    /* Invariants:
     *     ob_sval contains space for 'ob_size+1' elements.
     *     ob_sval[ob_size] == 0.
     *     ob_shash is the hash of the byte string or -1 if not computed yet.
     */
} PyBytesObject;
```
<h2>Bool</h2>
True and False are predefined subclasses of PyLong that are created at the start of runtime
<h2>Dict</h2>
```c++
typedef struct {
    Py_ssize_t ob_refcnt;
    PyTypeObject *ob_type;
    PyObject ob_base;

    /* Number of items in the dictionary */
    Py_ssize_t ma_used;

    /* Dictionary version: globally unique, value change each time
       the dictionary is modified */
    uint64_t ma_version_tag;

    PyDictKeysObject *ma_keys;

    /* If ma_values is NULL, the table is "combined": keys and values
       are stored in ma_keys.
       If ma_values is not NULL, the table is split:
       keys are stored in ma_keys and values are stored in ma_values */
    PyDictValues *ma_values;
} PyDictObject;

```
<h2>List (Look more into this one, it will require dynamic analysis to verify)</h2>
```c++
typedef struct {
    PyObject ob_base;
	Py_ssize_t ob_size;
    /* Vector of pointers to list elements.  list[0] is ob_item[0], etc. */
    PyObject **ob_item;

    /* ob_item contains space for 'allocated' elements.  The number
     * currently in use is ob_size.
     * Invariants:
     *     0 <= ob_size <= allocated
     *     len(list) == ob_size
     *     ob_item == NULL implies ob_size == allocated == 0
     * list.sort() temporarily sets allocated to -1 to detect mutations.
     *
     * Items must normally not be NULL, except during construction when
     * the list is not yet visible outside the function that builds it.
     */
    Py_ssize_t allocated;
} PyListObject;
```