#include <json-c/json.h>

int get_val (json_object *ptr, int a)
{
    int val;
    val =json_object_get_int(json_object_array_get_idx(ptr , a));
    return val;
}