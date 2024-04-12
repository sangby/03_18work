package com.qg.controller;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class BaseServlet extends HttpServlet {

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) {
        //先获取请求路径
        String requestUrl = req.getRequestURI();

        //截取请求路径中的方法名
        String methodName = requestUrl.substring(requestUrl.lastIndexOf("/") + 1);

        //调用方法
        Class<? extends BaseServlet> cla = this.getClass();
        try {
            Method method = cla.getMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);
            method.invoke(this,req, resp);

        } catch (NoSuchMethodException |InvocationTargetException |IllegalAccessException e) {
            e.printStackTrace();

        }
    }
}
