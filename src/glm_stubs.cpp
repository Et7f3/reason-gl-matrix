
#include <stdio.h>

#include <caml/mlvalues.h>
#include <caml/custom.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

extern "C" {
    static struct custom_operations objst_custom_ops = {
            identifier: (char*)"obj_st handling",
            finalize:    custom_finalize_default,
            compare:     custom_compare_default,
            hash:        custom_hash_default,
            serialize:   custom_serialize_default,
            deserialize: custom_deserialize_default
    };

    CAMLprim value
    caml_vec2_create(double x, double y) {
        CAMLparam0 ();
        glm::vec2 vec(x, y);
        float* vptr = (glm::value_ptr(vec));
        CAMLlocal1(v);
        v = caml_alloc_custom(&objst_custom_ops, sizeof(float) * 2, 0, 1);
        memcpy((void *)Data_custom_val(v), (void *)vptr, sizeof(float) * 2);
        CAMLreturn(v);
    }

    CAMLprim value
    caml_vec2_create_byte(value vX, value vY) {
        CAMLparam2(vX, vY);
        CAMLlocal1(v);
        v = caml_vec2_create(Double_val(vX), Double_val(vY));
        CAMLreturn(v);
    }

    CAMLprim value
    caml_vec3_create(double x, double y, double z) {
        CAMLparam0 ();
        glm::vec3 vec(x, y, z);
        float* vptr = (glm::value_ptr(vec));
        CAMLlocal1(v);
        v = caml_alloc_custom(&objst_custom_ops, sizeof(float) * 3, 0, 1);
        memcpy((void *)Data_custom_val(v), (void *)vptr, sizeof(float) * 3);
        CAMLreturn(v);
    }

    CAMLprim value
    caml_vec3_create_byte(value vX, value vY, value vZ) {
        CAMLparam3(vX, vY, vZ);
        CAMLlocal1(v);
        v = caml_vec3_create(Double_val(vX), Double_val(vY), Double_val(vZ));
        CAMLreturn(v);
    }

    CAMLprim value
    caml_vec4_create(double x, double y, double z, double w) {
        CAMLparam0 ();
        glm::vec4 vec(x, y, z, w);
        float* vptr = (glm::value_ptr(vec));
        CAMLlocal1(v);
        v = caml_alloc_custom(&objst_custom_ops, sizeof(float) * 4, 0, 1);
        memcpy((void *)Data_custom_val(v), (void *)vptr, sizeof(float) * 4);
        CAMLreturn(v);
    }

    CAMLprim value
    caml_vec4_create_byte(value vX, value vY, value vZ, value vW) {
        CAMLparam4(vX, vY, vZ, vW);
        CAMLlocal1(v);
        v = caml_vec4_create(Double_val(vX), Double_val(vY), Double_val(vZ), Double_val(vW));
        CAMLreturn(v);
    }

    CAMLprim value
    caml_quat_create(double x, double y, double z, double w) {
        CAMLparam0();
        float pQuat[4];
        pQuat[0] = w;
        pQuat[1] = x;
        pQuat[2] = y;
        pQuat[3] = z;

        CAMLlocal1(q);
        q = caml_alloc_custom(&objst_custom_ops, sizeof(float) * 4, 0, 1);
        memcpy((void*)Data_custom_val(q), (void *)pQuat, sizeof(float) * 4);
        CAMLreturn(q);
    };

    CAMLprim value
    caml_quat_create_byte(value vX, value vY, value vZ, value vW) {
        CAMLparam4(vX, vY, vZ, vW);
        CAMLlocal1(q); 

        q = caml_quat_create(Double_val(vX), Double_val(vY), Double_val(vZ), Double_val(vW));
        CAMLreturn(q);
    };

    double getByIndex(value vDat, int index) {
        float *vf = (float *)Data_custom_val(vDat);
        double d = vf[index];
        return d;
    }

    CAMLprim value
    caml_vec3_get_x(value vVec) {
        CAMLparam1(vVec);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vVec, 0));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_vec3_get_y(value vVec) {
        CAMLparam1(vVec);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vVec, 1));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_vec3_get_z(value vVec) {
        CAMLparam1(vVec);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vVec, 2));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_vec4_get_w(value vVec) {
        CAMLparam1(vVec);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vVec, 3));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_quat_get_w(value vQuat) {
        CAMLparam1(vQuat);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vQuat, 0));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_quat_get_x(value vQuat) {
        CAMLparam1(vQuat);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vQuat, 1));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_quat_get_y(value vQuat) {
        CAMLparam1(vQuat);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vQuat, 2));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_quat_get_z(value vQuat) {
        CAMLparam1(vQuat);
        CAMLlocal1(ret);
        ret = caml_copy_double(getByIndex(vQuat, 3));
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_vec3_debug_print(value vVec) {
        return Val_unit;
    }

    CAMLprim value
    caml_mat4_create(value unit) {
        CAMLparam0 ();
        glm::mat4 mat = glm::mat4(1.0f);
        float* ptr = (glm::value_ptr(mat));
        /* for(int i = 0; i < 16; i++) { */
        /*     printf("index: %d val: %f address: %d\n", i, ((float *)ptr)[i], (ptr + i)); */
        /* } */
        CAMLlocal1(v);
        v = caml_alloc_custom(&objst_custom_ops, sizeof(float) * 16, 0, 1);
        /* printf("data custom val pointer: %d\n", (void *)Data_custom_val(v)); */
        /* printf("data custom val pointer2: %d\n", (void *)Data_custom_val(v)); */

        memcpy((void *)Data_custom_val(v), (void *)ptr, sizeof(float) * 16);
        float *vf = (float *)Data_custom_val(v);
        /* printf("pointer: %d\n", vf); */
        /* for(int i = 0; i < 16; i++) { */
        /*     printf("index: %d val: %f address: %d\n", i, ((float *)vf)[i], (vf + i)); */
        /* } */
        CAMLreturn(v);
    }

    CAMLprim value
    caml_mat4_identity(value vMat) {
        float* matrix = (float*)(Data_custom_val(vMat));

        glm::mat4 glm_matrix = glm::mat4(1.0f);
        const float *outMatrix = (const float*)(glm::value_ptr(glm_matrix));

        for(int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }


    CAMLprim value
    caml_mat4_fromScaling(value vMat, value vVec) {
        float* matrix = (float*)(Data_custom_val(vMat));
        float* vec = (float*)(Data_custom_val(vVec));

        glm::mat4 glm_matrix = glm::mat4(1.0f);
        glm::vec3 glm_vec = glm::make_vec3(vec);

        glm::mat4 result = glm::scale(glm_matrix, glm_vec);

        const float *outMatrix = (const float*)(glm::value_ptr(result));

        for(int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_fromTranslation(value vMat, value vVec) {
        float* matrix = (float*)(Data_custom_val(vMat));
        float* vec = (float*)(Data_custom_val(vVec));

        glm::mat4 glm_matrix = glm::mat4(1.0f);
        glm::vec3 glm_vec = glm::make_vec3(vec);

        glm::mat4 result = glm::translate(glm_matrix, glm_vec);

        const float *outMatrix = (const float*)(glm::value_ptr(result));

        for(int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_transform_vec3(value vDest, value vVec, value vMat) {
        float* pDestVec3 = (float*)(Data_custom_val(vDest));
        float* pVec3 = (float*)(Data_custom_val(vVec));
        float* pMatrix = (float*)(Data_custom_val(vMat));

        glm::vec4 glm_vec = glm::vec4(pVec3[0], pVec3[1], pVec3[2], 1.0);
        glm::mat4 glm_matrix = glm::make_mat4(pMatrix);

        glm::vec4 result = glm_matrix * glm_vec;
        const float* pResult = (const float*)(glm::value_ptr(result));

        for(int i = 0; i < 3; i++) {
            pDestVec3[i] = pResult[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_rotate(value vMat, value vRad, value vAxis) {
        float* pMatrix = (float*)(Data_custom_val(vMat));
        float fRad = Double_val(vRad);
        float* pAxis = (float*)(Data_custom_val(vAxis));

        glm::vec3 glm_vec = glm::make_vec3(pAxis);
        glm::mat4 glm_matrix = glm::make_mat4(pMatrix);
        glm::mat4 result = glm::rotate(glm_matrix, fRad, glm_vec);

        const float* outMatrix = (const float*)(glm::value_ptr(result));
        for(int i = 0; i < 16; i++) {
            pMatrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_lookat(value vMat, value vEye, value vCenter, value vUp) {
        float* matrix = (float*)(Data_custom_val(vMat));
        float* vecEye = (float*)(Data_custom_val(vEye));
        float* vecCenter = (float*)(Data_custom_val(vCenter));
        float* vecUp = (float*)(Data_custom_val(vUp));

        glm::mat4 glm_matrix = glm::mat4(1.0f);
        glm::vec3 glm_vEye = glm::make_vec3(vecEye);
        glm::vec3 glm_vCenter = glm::make_vec3(vecCenter);
        glm::vec3 glm_vUp = glm::make_vec3(vecUp);

        glm::mat4 result = glm::lookAt(glm_vEye, glm_vCenter, glm_vUp);

        const float *outMatrix = (const float*)(glm::value_ptr(result));
        for(int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_perspective(value vMat, value vFov, value vAspectRatio, value vNear, value vFar) {
        float* matrix = (float *)(Data_custom_val(vMat));
        float fFov = Double_val(vFov);
        float fAspectRatio = Double_val(vAspectRatio);
        float fNear = Double_val(vNear);
        float fFar = Double_val(vFar);

        glm::mat4 result = glm::perspective(fFov, fAspectRatio, fNear, fFar);

        const float *outMatrix = (const float*)(glm::value_ptr(result));
        for (int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_ortho_native(value vMat, value vLeft, value vRight, value vBottom, value vTop, value vNear, value vFar) {
        float* matrix = (float *)(Data_custom_val(vMat));
        float fLeft = Double_val(vLeft);
        float fRight = Double_val(vRight);
        float fBottom = Double_val(vBottom);
        float fTop = Double_val(vTop);
        float fNear = Double_val(vNear);
        float fFar = Double_val(vFar);

        glm::mat4 result = glm::ortho(fLeft, fRight, fBottom, fTop, fNear, fFar);

        const float *outMatrix = (const float*)(glm::value_ptr(result));
        for (int i = 0; i < 16; i++) {
            matrix[i] = outMatrix[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_ortho_bytecode(value *argv, int argn) {
        return caml_mat4_ortho_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
    }

    CAMLprim value
    caml_mat4_multiply(value vOut, value vM1, value vM2) {
        float* pOutMatrix = (float*)(Data_custom_val(vOut));
        const float* pM1 = (const float*)(Data_custom_val(vM1));
        const float* pM2 = (const float*)(Data_custom_val(vM2));

        glm::mat4 m1 = glm::make_mat4(pM1);
        glm::mat4 m2 = glm::make_mat4(pM2);
        glm::mat4 result = m1 * m2;

        const float* pResult = (const float*)(glm::value_ptr(result));

        for(int i = 0; i < 16; i++) {
            pOutMatrix[i] = pResult[i];
        }

        return Val_unit;
    }

    CAMLprim value
    caml_mat4_get(value vMat, value vIndex) {
        CAMLparam2(vMat, vIndex);
        float v = getByIndex(vMat, Int_val(vIndex));
        CAMLlocal1(ret);
        ret = caml_copy_double(v);
        CAMLreturn(ret);
    }

    CAMLprim value
    caml_mat4_debug_print(value vMat) {
        const float* matrix = (const float*)(Data_custom_val(vMat));

        for(int i = 0; i < 16; i++) {
            printf("index: %d val: %f\n", i, matrix[i]);
        }
        return Val_unit;
    }
}
