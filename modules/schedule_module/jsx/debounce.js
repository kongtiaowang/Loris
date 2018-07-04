//Poor man's debounce
export function debounce (func, wait) {
    if (func.__timer != undefined) {
        clearTimeout(func.__timer);
    }
    func.__timer = setTimeout(() => {
        func.__timer = undefined;
        func();
    }, wait);
}
