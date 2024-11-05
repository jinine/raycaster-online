module.exports = {
    env: {
        browser: true,
        es2021: true,
    },
    parserOptions: {
        ecmaVersion: 12,
    },
    rules: {
        "no-restricted-globals": [
            "error",
            // { "name": "addEventListener", "message": "Use specific event handling instead." } 
        ]
    }
};
