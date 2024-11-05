const path = require('path');

module.exports = {
    entry: './src/index.js',
    output: {
        filename: 'bundle.js',
        path: path.resolve(__dirname, 'build'), // Changed to 'build'
        clean: true,
    },
    resolve: {
        fallback: {
            fs: false,
            path: require.resolve('path-browserify'),
            crypto: require.resolve('crypto-browserify'),
        },
    },
    module: {
        rules: [
            {
                test: /\.jsx?$/,
                exclude: /node_modules/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ['@babel/preset-env', '@babel/preset-react'],
                    },
                },
            },
            {
                test: /\.wasm$/,
                type: 'webassembly/async',
            },
        ],
    },
    devtool: 'source-map',
    devServer: {
        headers: {'Content-Type': 'application/wasm'},
        contentBase: path.join(__dirname, 'build'), // Updated for dev server
        compress: true,
        port: 9000,
    },
};
