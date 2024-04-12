package com.qg.util;

import com.alibaba.fastjson.JSONObject;
import com.qg.constant.Result;

import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class JsonUtil {
    /**
     * 设置json格式并返回
     *
     * @param result   结果
     * @param response 响应
     */
    public static void toJson(Result result, HttpServletResponse response){
        response.setContentType("text/json");
        //浏览器不缓存动态页面,保持每次打开页面都是一个最新的请求
        response.setHeader("Cache-Control","no-cache");

        //设置编码
        response.setCharacterEncoding("UTF-8");
        PrintWriter writer;
        try {
            writer = response.getWriter();
            writer.write(JSONObject.toJSONString(result));
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
