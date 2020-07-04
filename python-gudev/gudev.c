/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 3 "gudev.override"
#include <Python.h>
#define G_UDEV_API_IS_SUBJECT_TO_CHANGE
#include <gudev/gudev.h>
#include "pygobject.h"

/* Helper functions from gnome-python (gtksourceview) */
static PyObject *
glist_to_pylist_objs (const GList *source)
{
    const GList *iter;
    PyObject *dest = PyList_New (0);
    for (iter = source; iter != NULL; iter = iter->next)
    {
        PyObject *item = pygobject_new ((GObject *)iter->data);
        PyList_Append (dest, item);
        Py_DECREF (item);
    }
    return dest;
}

static PyObject *
gslist_to_pylist_strs (const GSList *source)
{
    const GSList *iter;
    PyObject *dest = PyList_New (0);
    for (iter = source; iter != NULL; iter = iter->next)
    {
        PyObject *item = PyString_FromString ((char *)iter->data);
        PyList_Append (dest, item);
        Py_DECREF (item);
    }
    return dest;
}

static PyObject *
strv_to_pylist (char **strv)
{
    gsize len, i;
    PyObject *list;

    len = strv ? g_strv_length (strv) : 0;
    list = PyList_New (len);

    for (i = 0; i < len; i++)
        PyList_SetItem (list, i, PyString_FromString (strv[i]));

    return list;
}

static gboolean
pylist_to_strv (PyObject *list,
                char   ***strvp)
{
    int i, len;
    char **ret;

    *strvp = NULL;

    if (list == Py_None)
        return TRUE;

    if (!PySequence_Check (list))
    {
        PyErr_Format (PyExc_TypeError, "argument must be a list or tuple of strings");
        return FALSE;
    }

    if ((len = PySequence_Size (list)) < 0)
        return FALSE;

    ret = g_new (char*, len + 1);
    for (i = 0; i <= len; ++i)
        ret[i] = NULL;

    for (i = 0; i < len; ++i)
    {
        PyObject *item = PySequence_GetItem (list, i);

        if (!item)
        {
            g_strfreev (ret);
            return FALSE;
        }

        if (!PyString_Check (item))
        {
            Py_DECREF (item);
            g_strfreev (ret);
            PyErr_Format (PyExc_TypeError, "argument must be a list of strings");
            return FALSE;
        }

        ret[i] = g_strdup (PyString_AsString (item));
        Py_DECREF (item);
    }

    *strvp = ret;
    return TRUE;
}

#line 109 "gudev.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyGUdevClient_Type;
PyTypeObject G_GNUC_INTERNAL PyGUdevDevice_Type;

#line 121 "gudev.c"



/* ----------- GUdevClient ----------- */

#line 114 "gudev.override"
static int
_wrap_g_udev_client_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "subsystems", NULL };
    gchar **subsystems = NULL;
    PyObject *list;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                        "O:GUdevClient.__init__",
                                        kwlist,
                                        &list))
        return -1;

    if (!pylist_to_strv(list, &subsystems)) {
        PyErr_SetString(PyExc_RuntimeError, "could not convert list");
        return -1;
    }
        
    pygobject_construct(self, "subsystems", subsystems, NULL);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GUdevClient");
        return -1;
    }
    return 0;
}
#line 154 "gudev.c"


#line 142 "gudev.override"
static PyObject *
_wrap_g_udev_client_query_by_subsystem (PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "subsystem", NULL };
    gchar *subsystem = NULL;
    GList *source;
    PyObject *dest;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|z:GUdevClient.query_by_subsystem",
                                     kwlist, &subsystem))
        return NULL;

    source = g_udev_client_query_by_subsystem(G_UDEV_CLIENT(self->obj), subsystem);
    dest = glist_to_pylist_objs(source);
    g_list_free(source);
    return dest;
}
#line 175 "gudev.c"


static PyObject *
_wrap_g_udev_client_query_by_device_number(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", "number", NULL };
    GUdevDeviceType type;
    PyObject *py_type = NULL;
    int number;
    GUdevDevice *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Oi:GUdev.Client.query_by_device_number", kwlist, &py_type, &number))
        return NULL;
    if (pyg_enum_get_value(G_TYPE_UDEV_DEVICE_TYPE, py_type, (gpointer)&type))
        return NULL;
    
    ret = g_udev_client_query_by_device_number(G_UDEV_CLIENT(self->obj), type, number);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_g_udev_client_query_by_device_file(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "device_file", NULL };
    char *device_file;
    GUdevDevice *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Client.query_by_device_file", kwlist, &device_file))
        return NULL;
    
    ret = g_udev_client_query_by_device_file(G_UDEV_CLIENT(self->obj), device_file);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_g_udev_client_query_by_sysfs_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "sysfs_path", NULL };
    char *sysfs_path;
    GUdevDevice *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Client.query_by_sysfs_path", kwlist, &sysfs_path))
        return NULL;
    
    ret = g_udev_client_query_by_sysfs_path(G_UDEV_CLIENT(self->obj), sysfs_path);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_g_udev_client_query_by_subsystem_and_name(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "subsystem", "name", NULL };
    char *subsystem, *name;
    GUdevDevice *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:GUdev.Client.query_by_subsystem_and_name", kwlist, &subsystem, &name))
        return NULL;
    
    ret = g_udev_client_query_by_subsystem_and_name(G_UDEV_CLIENT(self->obj), subsystem, name);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyGUdevClient_methods[] = {
    { "query_by_subsystem", (PyCFunction)_wrap_g_udev_client_query_by_subsystem, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "query_by_device_number", (PyCFunction)_wrap_g_udev_client_query_by_device_number, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "query_by_device_file", (PyCFunction)_wrap_g_udev_client_query_by_device_file, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "query_by_sysfs_path", (PyCFunction)_wrap_g_udev_client_query_by_sysfs_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "query_by_subsystem_and_name", (PyCFunction)_wrap_g_udev_client_query_by_subsystem_and_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGUdevClient_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gudev.Client",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGUdevClient_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_g_udev_client_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GUdevDevice ----------- */

static PyObject *
_wrap_g_udev_device_get_subsystem(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_subsystem(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_devtype(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_devtype(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_name(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_number(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_number(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_sysfs_path(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_sysfs_path(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_driver(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_driver(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_action(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_action(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_seqnum(PyGObject *self)
{
    guint64 ret;

    
    ret = g_udev_device_get_seqnum(G_UDEV_DEVICE(self->obj));
    
    return PyLong_FromUnsignedLongLong(ret);
}

static PyObject *
_wrap_g_udev_device_get_device_type(PyGObject *self)
{
    gint ret;

    
    ret = g_udev_device_get_device_type(G_UDEV_DEVICE(self->obj));
    
    return pyg_enum_from_gtype(G_TYPE_UDEV_DEVICE_TYPE, ret);
}

static PyObject *
_wrap_g_udev_device_get_device_number(PyGObject *self)
{
    int ret;

    
    ret = g_udev_device_get_device_number(G_UDEV_DEVICE(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_g_udev_device_get_device_file(PyGObject *self)
{
    const gchar *ret;

    
    ret = g_udev_device_get_device_file(G_UDEV_DEVICE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

#line 161 "gudev.override"
static PyObject *
_wrap_g_udev_device_get_device_file_symlinks (PyGObject *self)
{
    PyObject *py_ret;
    const char * const *ret;

    ret = g_udev_device_get_device_file_symlinks (G_UDEV_DEVICE (self->obj));
    py_ret = strv_to_pylist ((char**) ret);

    return py_ret;
}
#line 466 "gudev.c"


static PyObject *
_wrap_g_udev_device_get_parent(PyGObject *self)
{
    GUdevDevice *ret;

    
    ret = g_udev_device_get_parent(G_UDEV_DEVICE(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_g_udev_device_get_parent_with_subsystem(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "subsystem", "devtype", NULL };
    char *subsystem, *devtype;
    GUdevDevice *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:GUdev.Device.get_parent_with_subsystem", kwlist, &subsystem, &devtype))
        return NULL;
    
    ret = g_udev_device_get_parent_with_subsystem(G_UDEV_DEVICE(self->obj), subsystem, devtype);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 174 "gudev.override"
static PyObject *
_wrap_g_udev_device_get_property_keys (PyGObject *self)
{
    PyObject *py_ret;
    const char * const *ret;

    ret = g_udev_device_get_property_keys (G_UDEV_DEVICE (self->obj));
    py_ret = strv_to_pylist ((char**) ret);

    return py_ret;
}
#line 509 "gudev.c"


static PyObject *
_wrap_g_udev_device_has_property(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.has_property", kwlist, &key))
        return NULL;
    
    ret = g_udev_device_has_property(G_UDEV_DEVICE(self->obj), key);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_g_udev_device_get_property(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    const gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_property", kwlist, &key))
        return NULL;
    
    ret = g_udev_device_get_property(G_UDEV_DEVICE(self->obj), key);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_property_as_int(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_property_as_int", kwlist, &key))
        return NULL;
    
    ret = g_udev_device_get_property_as_int(G_UDEV_DEVICE(self->obj), key);
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_g_udev_device_get_property_as_uint64(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    guint64 ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_property_as_uint64", kwlist, &key))
        return NULL;
    
    ret = g_udev_device_get_property_as_uint64(G_UDEV_DEVICE(self->obj), key);
    
    return PyLong_FromUnsignedLongLong(ret);
}

static PyObject *
_wrap_g_udev_device_get_property_as_double(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    double ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_property_as_double", kwlist, &key))
        return NULL;
    
    ret = g_udev_device_get_property_as_double(G_UDEV_DEVICE(self->obj), key);
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_g_udev_device_get_property_as_boolean(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_property_as_boolean", kwlist, &key))
        return NULL;
    
    ret = g_udev_device_get_property_as_boolean(G_UDEV_DEVICE(self->obj), key);
    
    return PyBool_FromLong(ret);

}

#line 187 "gudev.override"
static PyObject *
_wrap_g_udev_device_get_property_as_strv (PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    gchar *key = NULL;
    PyObject *py_ret;
    const char * const *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s:GUdevClient.get_property_as_strv",
                                     kwlist, &key))
        return NULL;

    ret = g_udev_device_get_property_as_strv (G_UDEV_DEVICE (self->obj), key);
    py_ret = strv_to_pylist ((char**) ret);

    return py_ret;
}
#line 625 "gudev.c"


#line 206 "gudev.override"
static PyObject *
_wrap_g_udev_device_get_sysfs_attr_keys (PyGObject *self)
{
    PyObject *py_ret;
    const char * const *ret;

    ret = g_udev_device_get_sysfs_attr_keys (G_UDEV_DEVICE (self->obj));
    py_ret = strv_to_pylist ((char**) ret);

    return py_ret;
}
#line 640 "gudev.c"


static PyObject *
_wrap_g_udev_device_has_sysfs_attr(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.has_sysfs_attr", kwlist, &key))
        return NULL;
    
    ret = g_udev_device_has_sysfs_attr(G_UDEV_DEVICE(self->obj), key);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_g_udev_device_get_sysfs_attr(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;
    const gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_sysfs_attr", kwlist, &name))
        return NULL;
    
    ret = g_udev_device_get_sysfs_attr(G_UDEV_DEVICE(self->obj), name);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_g_udev_device_get_sysfs_attr_as_int(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_sysfs_attr_as_int", kwlist, &name))
        return NULL;
    
    ret = g_udev_device_get_sysfs_attr_as_int(G_UDEV_DEVICE(self->obj), name);
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_g_udev_device_get_sysfs_attr_as_uint64(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;
    guint64 ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_sysfs_attr_as_uint64", kwlist, &name))
        return NULL;
    
    ret = g_udev_device_get_sysfs_attr_as_uint64(G_UDEV_DEVICE(self->obj), name);
    
    return PyLong_FromUnsignedLongLong(ret);
}

static PyObject *
_wrap_g_udev_device_get_sysfs_attr_as_double(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;
    double ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_sysfs_attr_as_double", kwlist, &name))
        return NULL;
    
    ret = g_udev_device_get_sysfs_attr_as_double(G_UDEV_DEVICE(self->obj), name);
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_g_udev_device_get_sysfs_attr_as_boolean(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GUdev.Device.get_sysfs_attr_as_boolean", kwlist, &name))
        return NULL;
    
    ret = g_udev_device_get_sysfs_attr_as_boolean(G_UDEV_DEVICE(self->obj), name);
    
    return PyBool_FromLong(ret);

}

#line 219 "gudev.override"
static PyObject *
_wrap_g_udev_device_get_sysfs_attr_as_strv (PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    gchar *name = NULL;
    PyObject *py_ret;
    const char * const *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s:GUdevClient.get_sysfs_attr_as_strv",
                                     kwlist, &name))
        return NULL;

    ret = g_udev_device_get_sysfs_attr_as_strv (G_UDEV_DEVICE (self->obj), name);
    py_ret = strv_to_pylist ((char**) ret);

    return py_ret;
}
#line 756 "gudev.c"


static const PyMethodDef _PyGUdevDevice_methods[] = {
    { "get_subsystem", (PyCFunction)_wrap_g_udev_device_get_subsystem, METH_NOARGS,
      NULL },
    { "get_devtype", (PyCFunction)_wrap_g_udev_device_get_devtype, METH_NOARGS,
      NULL },
    { "get_name", (PyCFunction)_wrap_g_udev_device_get_name, METH_NOARGS,
      NULL },
    { "get_number", (PyCFunction)_wrap_g_udev_device_get_number, METH_NOARGS,
      NULL },
    { "get_sysfs_path", (PyCFunction)_wrap_g_udev_device_get_sysfs_path, METH_NOARGS,
      NULL },
    { "get_driver", (PyCFunction)_wrap_g_udev_device_get_driver, METH_NOARGS,
      NULL },
    { "get_action", (PyCFunction)_wrap_g_udev_device_get_action, METH_NOARGS,
      NULL },
    { "get_seqnum", (PyCFunction)_wrap_g_udev_device_get_seqnum, METH_NOARGS,
      NULL },
    { "get_device_type", (PyCFunction)_wrap_g_udev_device_get_device_type, METH_NOARGS,
      NULL },
    { "get_device_number", (PyCFunction)_wrap_g_udev_device_get_device_number, METH_NOARGS,
      NULL },
    { "get_device_file", (PyCFunction)_wrap_g_udev_device_get_device_file, METH_NOARGS,
      NULL },
    { "get_device_file_symlinks", (PyCFunction)_wrap_g_udev_device_get_device_file_symlinks, METH_NOARGS,
      NULL },
    { "get_parent", (PyCFunction)_wrap_g_udev_device_get_parent, METH_NOARGS,
      NULL },
    { "get_parent_with_subsystem", (PyCFunction)_wrap_g_udev_device_get_parent_with_subsystem, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_property_keys", (PyCFunction)_wrap_g_udev_device_get_property_keys, METH_NOARGS,
      NULL },
    { "has_property", (PyCFunction)_wrap_g_udev_device_has_property, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_property", (PyCFunction)_wrap_g_udev_device_get_property, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_property_as_int", (PyCFunction)_wrap_g_udev_device_get_property_as_int, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_property_as_uint64", (PyCFunction)_wrap_g_udev_device_get_property_as_uint64, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_property_as_double", (PyCFunction)_wrap_g_udev_device_get_property_as_double, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_property_as_boolean", (PyCFunction)_wrap_g_udev_device_get_property_as_boolean, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_property_as_strv", (PyCFunction)_wrap_g_udev_device_get_property_as_strv, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_sysfs_attr_keys", (PyCFunction)_wrap_g_udev_device_get_sysfs_attr_keys, METH_NOARGS,
      NULL },
    { "has_sysfs_attr", (PyCFunction)_wrap_g_udev_device_has_sysfs_attr, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_sysfs_attr", (PyCFunction)_wrap_g_udev_device_get_sysfs_attr, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_sysfs_attr_as_int", (PyCFunction)_wrap_g_udev_device_get_sysfs_attr_as_int, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_sysfs_attr_as_uint64", (PyCFunction)_wrap_g_udev_device_get_sysfs_attr_as_uint64, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_sysfs_attr_as_double", (PyCFunction)_wrap_g_udev_device_get_sysfs_attr_as_double, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_sysfs_attr_as_boolean", (PyCFunction)_wrap_g_udev_device_get_sysfs_attr_as_boolean, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_sysfs_attr_as_strv", (PyCFunction)_wrap_g_udev_device_get_sysfs_attr_as_strv, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGUdevDevice_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gudev.Device",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGUdevDevice_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

const PyMethodDef pygudev_functions[] = {
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
pygudev_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_enum_add(module, "DeviceType", strip_prefix, G_TYPE_UDEV_DEVICE_TYPE);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
pygudev_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }


#line 911 "gudev.c"
    pygobject_register_class(d, "GUdevClient", G_UDEV_TYPE_CLIENT, &PyGUdevClient_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(G_UDEV_TYPE_CLIENT);
    pygobject_register_class(d, "GUdevDevice", G_UDEV_TYPE_DEVICE, &PyGUdevDevice_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(G_UDEV_TYPE_DEVICE);
}
