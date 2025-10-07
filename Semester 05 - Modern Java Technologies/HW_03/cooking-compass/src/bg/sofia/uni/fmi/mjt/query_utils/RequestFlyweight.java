package bg.sofia.uni.fmi.mjt.query_utils;

import java.net.URI;
import java.net.http.HttpRequest;
import java.util.HashMap;
import java.util.Map;

public class RequestFlyweight {
    private static final Object LOCK = new Object();

    private static volatile RequestFlyweight instance;

    private final Map<URI, HttpRequest> requests;

    private RequestFlyweight() {
        requests = new HashMap<>();
    }

    public static RequestFlyweight getInstance() {
        RequestFlyweight result = instance;
        if (result != null) {
            return result;
        }
        synchronized (RequestFlyweight.class) {
            if (instance == null) {
                instance = new RequestFlyweight();
            }
            return instance;
        }
    }

    public HttpRequest getRequest(URI uri) {
        if (requests.containsKey(uri)) {
            return requests.get(uri);
        }

        HttpRequest request = HttpRequest.newBuilder().GET().uri(uri).build();
        synchronized (LOCK) {
            requests.put(uri, request);
        }
        return request;
    }
}
