<h2>Classes</h2>
Classes are treated as separate modules, so they have their own module function which does the normal stuff including function setup for all class methods, it also initialized some attributes at the beginning like the qualname.

PyObject_SetAttr and PyObject_GetAttr are used to access attributes of the class.

