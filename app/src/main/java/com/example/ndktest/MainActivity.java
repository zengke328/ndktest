package com.example.ndktest;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {


    static {
        System.loadLibrary("jni-test");
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final TextView textView = findViewById(R.id.text);
        textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                textView.setText(get());
            }
        });
        textView.setText(get());
        set("hello world set jni");
    }


    private native String get();

    private native void set(String str);

    public static void methodCalledByJni(String string) {
        Log.e("MainActivity", "methodCalledByJni= " + string);
    }


}
