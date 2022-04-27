use std::ffi::CString;
use std::os::raw::c_char;

#[no_mangle]
pub extern "C" fn maths_in_rust(inp: i32) -> i32 {
    let factor = 10i32;
    return inp.checked_mul(factor).unwrap();
}

#[no_mangle]
pub extern "C" fn string_from_rust(number_to_add: i32) -> *mut c_char {
    CString::new(format!(
        "Rust is passing this string with number: {number_to_add}\n"
    ))
    .expect("Failed to alloc CString")
    .into_raw()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_my_maths_in_rust() {
        assert_eq!(50, maths_in_rust(5));
    }

    #[test]
    fn test_more_maths() {
        assert_eq!(250, maths_in_rust(25));
    }
}
