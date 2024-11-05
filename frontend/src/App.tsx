import React, { useEffect, useRef } from 'react';
import Module from './wasm/raycaster.js';

const RaycasterGame = () => {
    const canvasRef = useRef<HTMLCanvasElement | null>(null); // Reference to the canvas element

    useEffect(() => {
        const loadWasm = async () => {
            try {
                const response = await fetch('wasm/raycaster.wasm');
                if (!response.ok) throw new Error(`Failed to fetch .wasm file: ${response.statusText}`);
        
                const buffer = await response.arrayBuffer();
                Module.instantiateWasm({ wasmBinary: buffer });
                
                Module.onRuntimeInitialized = () => {
                    Module._main();
                };
            } catch (error) {
                console.error('Error loading WASM module:', error);
            }
        };
        

        loadWasm();

        const handleKeyPress = (event: KeyboardEvent) => {
            const keys = new Array(256).fill(false);
            keys[event.keyCode] = true; 
            if (Module && Module._updateKeys) {
                Module._updateKeys(keys);
            }
        };

        document.addEventListener('keydown', handleKeyPress);

        return () => {
            document.removeEventListener('keydown', handleKeyPress);
        };
    }, []);

    return (
        <div>
            <h1>Raycaster Game</h1>
            <canvas ref={canvasRef} id="gameCanvas" width="120" height="40" />
        </div>
    );
};

export default RaycasterGame;
