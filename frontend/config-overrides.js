const path = require('path');

module.exports = function override(config, env) {
    // Add polyfills for Node.js core modules
    config.resolve.fallback = {
        ...config.resolve.fallback, // Keep existing fallbacks
        path: require.resolve('path-browserify'),
        fs: false, // Disable fs since it's not available in the browser
        http: require.resolve('stream-http'),
        https: require.resolve('https-browserify'),
        stream: require.resolve('stream-browserify'),
    };
    return config;
};
