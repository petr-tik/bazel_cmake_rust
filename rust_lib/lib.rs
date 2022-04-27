#[no_mangle]
pub extern "C" fn maths_in_rust(inp: i32) -> i32 {
    let factor = 10i32;
    return inp.checked_mul(factor).unwrap();
}

#[no_mangle]
pub extern "C" fn string_from_rust(number_to_add: i32) -> String {
    format!("Hello World {number_to_add}")
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_my_maths_in_rust() {
        assert_eq!(50, maths_in_rust(5));
    }

    #[test]
    fn test_my_string() {
        assert_eq!(string_from_rust(1), "Hello World 1");
    }
}
