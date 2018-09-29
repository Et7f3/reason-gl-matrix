type t;
external create_internal: unit => t = "caml_vec3_create";

let zero = () => create_internal();

external set: (t, float, float, float) => unit = "caml_vec3_set";
external get_x: t => float = "caml_vec3_get_x";
external get_y: t => float = "caml_vec3_get_y";
external get_z: t => float = "caml_vec3_get_z";

external debug_print: t => float = "caml_vec3_debug_print";

let create = (x, y, z) => {
    let vec = create_internal();
    set(vec, x, y, z);
    vec
};
